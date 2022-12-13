
number=0

while [ $number -le 100 ]
do
	echo "test" $number
	export ARG=$(./push_swap_tester/random_numbers 100 -2147483648)
 	./push_swap $ARG | ./checker $ARG | grep -E 'KO|Error'
	./push_swap $ARG | ./checker_Mac $ARG | grep -E 'KO|Error'
	
	((number++))
done
