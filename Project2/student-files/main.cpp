#include <iostream>

#include "string_bst.hpp"
#include "max_heap.hpp"
#include "text_item.hpp"
#include "util.hpp"

using namespace std;

//--- PART 1A: Implementation and testing of heap insert
void heap_insert_tests(max_heap &hp) {
	text_item temp;
	std::string word = "item";
	int random_num;
	long int seed = long(time(0));    // seed for random number generator
	srand(seed);
	int word_freq;


	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully
	//    test the correctness of the insert function.
	int i = 0;
	while (!hp.full()) {
		random_num = rand() % 100;
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;
		i++;
	}
	int heap_capacity = hp.size();

	//--- Specific insert functionality that should be tested:

	// insert without any swap_ups needed
		// <INSERT TEST(S) HERE>

		cout << endl << "Testing insert without any swap_ups needed " << endl;
		max_heap testMaxHeap1(heap_capacity);
		i = 0;
		while (!testMaxHeap1.full()){
			string text = word;
			word_freq = (heap_capacity - i) * 10;
			text += std::to_string(i+1);
			std::cout << "adding " << text << ",  with number " << word_freq << " to heap" << std::endl;
			testMaxHeap1.insert(text_item{text, word_freq});
			temp = testMaxHeap1.top();
			std::cout << "Top of heap is: " << temp << std::endl;
			i++;
		}

	// insert with a swap_up / multiple swap_ups
		// <INSERT TEST(S) HERE>

		cout << endl << "Testing insert with a swap_up / multiple swap_ups " << endl;
		max_heap testMaxHeap2(heap_capacity);
		i = 0;
		while (!testMaxHeap2.full()) {
			string text = word;
			word_freq = (i + 1) * 10;
			text += std::to_string(i+1);
			std::cout << "adding " << text << ",  with number " << word_freq << " to heap" << std::endl;
			testMaxHeap2.insert(text_item{text, word_freq});
			temp = testMaxHeap2.top();
			std::cout << "Top of heap is: " << temp << std::endl;
			i++;
		}
}

//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;

	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
	//--- This does not fully test delete_max functionality.
	while (!hp.empty()) {
		temp = hp.delete_max();
		std::cout << "Item returned from heap delete: "<< temp << std::endl;
		if (!hp.empty()){
			temp = hp.top();
			std::cout << "Top of heap is now: " << temp << std::endl;
		}
		else {
			std::cout << "Heap is now empty. Can't access the top of the heap" << std::endl;
		}
	}

	//--- Specific insert functionality that should be tested:

	// remove_max works when swap_down with left child
		// <INSERT TEST(S) HERE>
		cout << endl << "Testing remove_max works when swap_down with left child " << endl;
		max_heap testLeftChild(6);
		testLeftChild.insert(text_item{"item1", 50});
		testLeftChild.insert(text_item{"item2", 40});
		testLeftChild.insert(text_item{"item3", 30});
		testLeftChild.insert(text_item{"item4", 20});
		testLeftChild.insert(text_item{"item5", 10});
		cout << "The testLeftChild heap array by index is: " << endl << "	text_item{'item1', 50}, text_item{'item2', 40}, text_item{'item3', 30}, text_item{'item4', 20}, text_item{'item5', 10}" << endl;
		while (!testLeftChild.empty()) {
			temp = testLeftChild.delete_max();
			std::cout << "Item returned from heap delete: "<< temp << std::endl;
			if (!testLeftChild.empty()){
				temp = testLeftChild.top();
				std::cout << "Top of heap is now: " << temp << std::endl;
			}
			else {
				std::cout << "Heap is now empty. Can't access the top of the heap" << std::endl;
			}
		}


	// remove_max workd when swap_down with right child
		// <INSERT TEST(S) HERE>
		cout << endl << "Testing remove_max works when swap_down with right child " << endl;
		max_heap testRightChild(6);
		testRightChild.insert(text_item{"item1", 50});
		testRightChild.insert(text_item{"item2", 30});
		testRightChild.insert(text_item{"item3", 40});
		testRightChild.insert(text_item{"item4", 20});
		testRightChild.insert(text_item{"item5", 10});
		cout << "The testRightChild heap array by index is: " << endl << "	text_item{'item1', 50}, text_item{'item2', 30}, text_item{'item3', 40}, text_item{'item4', 20}, text_item{'item5', 10}" << endl;
		while (!testRightChild.empty()) {
			temp = testRightChild.delete_max();
			std::cout << "Item returned from heap delete: "<< temp << std::endl;
			if (!testRightChild.empty()){
				temp = testRightChild.top();
				std::cout << "Top of heap is now: " << temp << std::endl;
			}
			else {
				std::cout << "Heap is now empty. Can't access the top of the heap" << std::endl;
			}
		}

	// remove_max on an empty heap (should throw exception similar to top())
		// <INSERT TEST(S) HERE>
		cout << endl << "Testing remove_max on an empty heap (should throw logic_error) " << endl;
		try {
			max_heap testEmptyHeap(5);
			testEmptyHeap.delete_max();
		} catch (std::logic_error e) {
			cout << "delete_max() error caught: " << e.what() << endl;
		}

}

//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;

	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}

	//--- Specific word_frequency functionality that should be tested:

	// can search through both left and right subtrees if not found at current node
	cout << endl << "Testing search through both left and right subtrees if not found at current node " << endl;

	string_bst* testTree = new string_bst();
	testTree->insert("c");
	testTree->insert("d");
	testTree->insert("a");
	testTree->insert("b");
	testTree->insert("c");
	testTree->insert("a");
	testTree->insert("a");
	testTree->insert("b");
	cout << "New custom BST is created. Root: " << testTree->get_root()->data << endl;
	testTree->display();

	cout << endl << "		1)Testing search through left subtrees " << endl;
	if (testTree->size() > 1) {
		string to_find = "a";
		int num_times = testTree->word_frequency(to_find);
		std::cout << "Found: "<< to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}

	cout << endl << "		2)Testing search through right subtrees " << endl;
	if (testTree->size() > 1) {
		string to_find = "d";
		int num_times = testTree->word_frequency(to_find);
		std::cout << "Found: "<< to_find <<
			" in the input file " << num_times
			<< " time(s)." << std::endl;
	}

	// returns 0 if word is not found
	cout << endl << "Testing returns 0 if word is not found" << endl;
	if (tree.size() > 1) {
		string to_find = "NOTINTHETREE";
		int num_times = testTree->word_frequency(to_find);
		std::cout << "Couldn't find: "<< to_find <<
			" in the input file. The freq is: " << num_times
			<< " time(s)." << std::endl;
	}

	delete testTree;

}

//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
	int count = 1;

	while (hp.size() > 0 && count <= 5) {
		text_item top = hp.delete_max();
		std::cout << top << std::endl;
		count++;
	}
}


void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least "
		<< num_letters << " letters ***" << std::endl;
	int count = 1;
	while (hp.size() > 0 && count <= 5) {
		text_item top = hp.delete_max();
		if (top.word.length() >= num_letters) {
			std::cout << top << std::endl;
			count++;
		}
	}
	//--- Add code to print out the 5 most common
	//--- words of length at least <num_letters>


}

void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with "
		<< starts_with_letter << " ***" << std::endl;
	//--- Add code to print out the 5 most common words
	//--- that start with the letter <starts_with_letter>
	int count = 1;
	while (hp.size() > 0 && count <= 5) {
		text_item top = hp.delete_max();
		if (top.word[0] == starts_with_letter) {
			std::cout << top << std::endl;
			count++;
		}
	}

}

void heap_tester() {
	text_item temp;
	int heap_size; //feel free to create heaps of other sizes when testing
	cout << "How many items should be added to heap?" << endl
	<<"(heap_size will be 10 by default if number is not entered or number is 0)" << endl;
	cin >> heap_size;
	heap_size = (heap_size) ? heap_size : 10;
	max_heap hp(heap_size);
	std::cout << "Created heap of size " << heap_size << std::endl;

	//--- Testing heap size and top
	std::cout << "Current number of items in heap is: " << hp.size() << std::endl;
	try {
		temp = hp.top(); //should throw and exception without items in heap
		std::cout << "Top of heap is: " << temp << std::endl;
	} catch (std::logic_error e) {
		std::cout << e.what() << std::endl;
	}
	// PART 1A:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1A" << std::endl;
	heap_insert_tests(hp);
	// PART 1B:
	std::cout << std::endl << "BEGINNING TESTS FOR PART 1B" << std::endl;
	heap_delete_tests(hp);
}

void text_analysis_tester(string_bst &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 3" << std::endl;
	overall_most_freq(copy_to_heap(tree));
	std::cout << std::endl;
	at_least_length(copy_to_heap(tree), 6); // change the 8 to test other string-lengths
	std::cout << std::endl;
	starts_with(copy_to_heap(tree), 'c'); // change the 'c' to test words that starts_with_letter
											// with different characters
}

int main(int argc, char* argv[]) {

	//--- Part 1: max_heap implementation
	heap_tester();

	//--- Part 2: string_bst implementation
	string_bst tree;
	load_bst("sample2.txt", tree); // create a bst from an input file.
	tree_tester(tree);			//sample2.txt contains a much bigger file

	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);

}
