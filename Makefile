prog: Assignment1.cpp LinkedList.h
	g++ -o prog Assignment1.cpp LinkedList.h
	./prog <input1.txt >output1.txt
clean:
	rm -f prog output1.txt
