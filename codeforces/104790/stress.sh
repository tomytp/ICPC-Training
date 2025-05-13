P=k
make ${P} gen || exit 1
for ((i = 1; ; i++)) do
	./gen > in_
	python3 tool.py -f in_ ./k
done
