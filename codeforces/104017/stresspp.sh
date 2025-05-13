P=l
make ${P} ${P}2 genpp || exit 1
for ((i = 1; ; i++)) do
	./genpp $i > in__
	./${P} < in__ > out__
	./${P}2 < in__ > out2__
	echo "--> entrada:"
	cat in__
	echo "--> saida1:"
	cat out__
	echo "--> saida2:"
	cat out2__
	echo $i
done
