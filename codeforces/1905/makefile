CXX = g++
CXXFLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g -Wall -Wshadow -std=c++17 -Wno-unused-result -Wno-sign-compare -Wno-char-subscripts

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

.PHONY: all clean test

clean:
	rm -f main *.exe *.o temp_output a b c d e f g h i j k l m n

test:
	$(CXX) $(CXXFLAGS) $*.cpp -o main

	@for i in in[0-9]*; do \
		if [ -f "$$i" ]; then \
			test_num=$${i#in}; \
			expected_output="out$$test_num"; \
			if [ -f "$$expected_output" ]; then \
				./main < "$$i" > temp_output; \
				if diff -Z -B temp_output "$$expected_output" > /dev/null; then \
					echo -e "$(GREEN)Test $$test_num: PASSED$(NC)"; \
				else \
					echo -e "$(RED)Test $$test_num: FAILED$(NC)"; \
					echo "Expected:"; \
					cat "$$expected_output"; \
					echo "Got:"; \
					cat temp_output; \
				fi; \
			fi; \
		fi; \
	done
	@rm -f temp_output

test-%: %.cpp
	$(CXX) $(CXXFLAGS) $*.cpp -o $*

	@for i in in$*[0-9]*; do \
		if [ -f "$$i" ]; then \
			test_num=$${i#in$*}; \
			expected_output="out$*$$test_num"; \
			if [ -f "$$expected_output" ]; then \
				./$* < "$$i" > temp_output; \
				if diff -Z -B temp_output "$$expected_output" > /dev/null; then \
					echo "$(GREEN)Test $$test_num: PASSED$(NC)"; \
				else \
					echo "$(RED)Test $$test_num: FAILED$(NC)"; \
					echo "Expected:"; \
					cat "$$expected_output"; \
					echo "Got:"; \
					cat temp_output; \
				fi; \
			fi; \
		fi; \
	done
	@rm -f temp_output