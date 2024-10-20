#include <iostream>
#include <string>

// 1. Реверсування строки
void reverseStringMain(const std::string& str) {
	if (str.empty()) {
		return;
	}
	reverseStringMain(str.substr(1));
	std::cout << str[0];
}

void reverseStringTail(const std::string& str, int index = 0) {
	if (index == str.size()) {
		return;
	}
	reverseStringTail(str, index + 1);
	std::cout << str[index];
}

// 2. Обмін місцями сусідніх вузлів зв’язаного списку
struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* swapPairsMain(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* first = head;
	ListNode* second = head->next;
	first->next = swapPairsMain(second->next);
	second->next = first;
	return second;
}

ListNode* swapPairsTailHelper(ListNode* head, ListNode* newHead, ListNode* prevTail) {
	if (!head || !head->next) {
		if (prevTail != nullptr) {
			prevTail->next = head;
		}
		return newHead;
	}

	ListNode* first = head;
	ListNode* second = head->next;
	first->next = second->next;
	second->next = first;

	if (prevTail != nullptr) {
		prevTail->next = second;
	}
	else {
		newHead = second;
	}

	return swapPairsTailHelper(first->next, newHead, first);
}

ListNode* swapPairsTail(ListNode* head) {
	return swapPairsTailHelper(head, nullptr, nullptr);
}

void printList(ListNode* head) {
	while (head != nullptr) {
		std::cout << head->val << " ";
		head = head->next;
	}
	std::cout << std::endl;
}

// 3. Числа Фібоначчі
int fibonacciMain(int n) {
	if (n <= 1) {
		return n;
	}
	return fibonacciMain(n - 1) + fibonacciMain(n - 2);
}

int fibonacciTailHelper(int n, int a = 0, int b = 1) {
	if (n == 0) {
		return a;
	}
	if (n == 1) {
		return b;
	}
	return fibonacciTailHelper(n - 1, b, a + b);
}

int fibonacciTail(int n) {
	return fibonacciTailHelper(n);
}

// 4. Унікальні комбінації для підйому по сходах
int climbStairsMain(int n) {
	if (n <= 2) {
		return n;
	}
	return climbStairsMain(n - 1) + climbStairsMain(n - 2);
}

int climbStairsTailHelper(int n, int a = 1, int b = 1) {
	if (n <= 1) {
		return b;
	}
	return climbStairsTailHelper(n - 1, b, a + b);
}

int climbStairsTail(int n) {
	return climbStairsTailHelper(n);
}

// 5. Піднесення до степеня
double powerMain(double x, int n) {
	if (n == 0) {
		return 1;
	}
	if (n < 0) {
		x = 1 / x;
		n = -n;
	}
	if (n % 2 == 0) {
		return powerMain(x * x, n / 2);
	}
	return x * powerMain(x, n - 1);
}

double powerTailHelper(double x, int n, double acc) {
	if (n == 0) {
		return acc;
	}
	if (n < 0) {
		return powerTailHelper(1 / x, -n, acc);
	}
	if (n % 2 == 0) {
		return powerTailHelper(x * x, n / 2, acc);
	}
	return powerTailHelper(x, n - 1, acc * x);
}

double powerTail(double x, int n) {
	return powerTailHelper(x, n, 1.0);
}

int main() {
	// Завдання 1: Реверсування строки
	std::string input1 = "tiger";
	std::cout << "Reverse (Main): ";
	reverseStringMain(input1);
	std::cout << std::endl;

	std::string input2 = "work";
	std::cout << "Reverse (Tail): ";
	reverseStringTail(input2);
	std::cout << std::endl << std::endl;

	// Завдання 2: Обмін місцями сусідніх вузлів зв’язаного списку
	ListNode* head1 = new ListNode(1);
	head1->next = new ListNode(2);
	head1->next->next = new ListNode(3);
	head1->next->next->next = new ListNode(4);

	ListNode* result1 = swapPairsMain(head1);
	std::cout << "Swap Pairs (Main): ";
	printList(result1);

	ListNode* head2 = new ListNode(1);
	head2->next = new ListNode(2);
	head2->next->next = new ListNode(3);
	head2->next->next->next = new ListNode(4);

	ListNode* result2 = swapPairsTail(head2);
	std::cout << "Swap Pairs (Tail): ";
	printList(result2);
	std::cout << std::endl;

	// Завдання 3: Числа Фібоначчі
	int fibInput1 = 5;
	std::cout << "Fibonacci (Main) for " << fibInput1 << ": " << fibonacciMain(fibInput1) << std::endl;

	int fibInput2 = 6;
	std::cout << "Fibonacci (Tail) for " << fibInput2 << ": " << fibonacciTail(fibInput2) << std::endl << std::endl;

	// Завдання 4: Унікальні комбінації для підйому по сходах
	int stairsInput1 = 4;
	std::cout << "Climb Stairs (Main) for " << stairsInput1 << ": " << climbStairsMain(stairsInput1) << std::endl;

	int stairsInput2 = 5;
	std::cout << "Climb Stairs (Tail) for " << stairsInput2 << ": " << climbStairsTail(stairsInput2) << std::endl << std::endl;

	// Завдання 5: Піднесення до степеня
	double x1 = 2.0;
	int n1 = 10;
	std::cout << "Power (Main) of " << x1 << " to the power of " << n1 << ": " << powerMain(x1, n1) << std::endl;

	double x2 = 2.1;
	int n2 = 3;
	std::cout << "Power (Tail) of " << x2 << " to the power of " << n2 << ": " << powerTail(x2, n2) << std::endl;

	return 0;
}
