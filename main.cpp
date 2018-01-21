#include <iostream>
#include <string>
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
	
	//--- Testing insert functionality
	std::cout << "*** TESTING INSERT ***" << std::endl;
	//--- This adds 5 items to the heap with random numbers
	//    and prints out the top, but it does not fully 
	//    test the correctness of the insert function.
	for (int i = 0 ; i < 5; i++) {
		random_num = rand() % 100;
		string text = word;
		text += std::to_string(i+1);
		std::cout << "adding " << text << ",  with number " << random_num << " to heap" << std::endl;
		hp.insert(text_item{text, random_num});	
		temp = hp.top();
		std::cout << "Top of heap is: " << temp << std::endl;		
	}
	std::cout << std::endl;
	//--- Specific insert functionality that should be tested:
	std::cout << "Begin Insert Tests (No Swap Ups Needed)" << std::endl;	
	// insert without any swap_ups needed
		// <INSERT TEST(S) HERE>
	text_item temp1;
	text_item temp2;
	text_item temp3;
	max_heap heap(2);
    temp1.word = "blue";
    temp1.freq = 2;
    temp2.word = "red";
    temp2.freq = 1;
    std::cout << "adding " << temp1.word << ",  with number " << temp1.freq << " to heap" << std::endl;
    heap.insert(temp1);
    std::cout << "Top of heap is: " << heap.top() << std::endl;
    std::cout << "adding " << temp2.word << ",  with number " << temp2.freq << " to heap" << std::endl;
    heap.insert(temp2);
    std::cout << "Top of heap is: " << heap.top() << std::endl;
	// insert with a swap_up / multiple swap_ups
		// <INSERT TEST(S) HERE>
    std::cout << std::endl;
    std::cout << "Begin Insert Tests (Multiple Swap Ups Needed)" << std::endl;	
	max_heap heap2(3);
    temp1.word = "blue";
    temp1.freq = 2;
    temp2.word = "red";
    temp2.freq = 1;
    temp3.word = "green";
    temp3.freq = 3;
    std::cout << "adding " << temp2.word << ",  with number " << temp2.freq << " to heap2" << std::endl;
    heap2.insert(temp2);
    std::cout << "Top of heap is: " << heap2.top() << std::endl;
    std::cout << "adding " << temp1.word << ",  with number " << temp1.freq << " to heap2" << std::endl;
    heap2.insert(temp1);
    std::cout << "Top of heap is: " << heap2.top() << std::endl;
    std::cout << "adding " << temp3.word << ",  with number " << temp3.freq << " to heap2" << std::endl;
    heap2.insert(temp3);
    std::cout << "Top of heap is: " << heap2.top() << std::endl;
}

//--- PART 1B: Implementation and testing of heap delete
void heap_delete_tests(max_heap &hp) {
	text_item temp;
	text_item temp1;
	text_item temp2;
	text_item temp3;
	text_item temp4;
	text_item temp5;
	
	//--- Testing deleteMax functionality
	std::cout << "*** TESTING DELETEMAX ***" << std::endl;
	//--- This does not fully test delete_max functionality.
	if (hp.size() > 1) {
		temp = hp.delete_max();
		std::cout << "Item returned from heap delete: "<< temp << std::endl;
		temp = hp.top();
		std::cout << "Top of heap is now: " << temp << std::endl;	
	}
	
	//--- Specific insert functionality that should be tested:
	
	// remove_max works when swap_down with left child
		// <INSERT TEST(S) HERE>
	std::cout << std::endl;
	std::cout << "Begin DELETEMAX tests (swap_down with left child)" << std::endl;
	max_heap heap3(3);
    temp1.word = "blue";
    temp1.freq = 1;
    temp2.word = "red";
    temp2.freq = 2;
    temp3.word = "green";
    temp3.freq = 3;
    heap3.insert(temp3);
    heap3.insert(temp2);
    heap3.insert(temp1);
    std::cout << "Item returned from heap delete: "<< heap3.delete_max() << std::endl;

	// remove_max works when swap_down with right child
		// <INSERT TEST(S) HERE>
	std::cout << std::endl;
	std::cout << "Begin DELETEMAX tests (swap_down with right child)" << std::endl;
	max_heap heap5(5);
	temp1.word = "ten";
    temp1.freq = 10;
    temp2.word = "eight";
    temp2.freq = 8;
    temp3.word = "nine";
    temp3.freq = 9;
    temp4.word = "seven";
    temp4.freq = 7;
    temp5.word = "six";
    temp5.freq = 6;
    heap5.insert(temp1);
    heap5.insert(temp2);
    heap5.insert(temp3);
    heap5.insert(temp4);
    heap5.insert(temp5);
    std::cout << "Item returned from heap delete: "<< heap5.delete_max() << std::endl;
    std::cout << "New heap top: "<< heap5.top() << std::endl;


	// remove_max on an empty heap (should throw exception similar to top())
		// <INSERT TEST(S) HERE>
	std::cout << std::endl;
	std::cout << "Begin DELETEMAX tests (empty)" << std::endl;
	max_heap heap0(0);
	try{
  	heap0.delete_max();
	}catch(std::logic_error&){
   	std::cout << "Error when attempting to delete from empty heap!" << std::endl;
	}

}

//--- PART 2: Implementation and testing of BST word_frequency
void tree_tester(string_bst const &tree) {
	std::cout << std::endl << "BEGINNING TESTS FOR PART 2" << std::endl;
	
	//--- Testing word_frequency functionality
	//--- This does not fully test word_frequency functionality.
	if (tree.size() > 1) {
		std::cout << std::endl << "BST we are to traverse:" << std::endl;
		tree.display();
		std::cout << std::endl;
		string to_find = "difficult";
		int num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;


		to_find = "to";
		num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;


		to_find = "alphabetically";
		num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;


		to_find = "word";
		num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
	}
	
	//--- Specific word_frequency functionality that should be tested:
	string to_find = "";
	int num_times = 0;
	// can search through both left and right subtrees if not found at current node
		// <INSERT TEST(S) HERE>
	string_bst tree3;
	load_bst("sample3.txt", tree3);
	to_find = "abracadabra";
		num_times = tree3.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;

	to_find = "bonjour";
		num_times = tree3.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;

	to_find = "comment";
		num_times = tree3.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;

	// returns 0 if word is not found
		// <INSERT TEST(S) HERE>
	std::cout << "word_frequency functionality test (word not found)" << std::endl;
		to_find = "watermelon";
		num_times = tree.word_frequency(to_find);
		std::cout << "Found: "<< to_find << 
			" in the input file " << num_times 
			<< " time(s)." << std::endl;
			
}

//--- PART 3: Implementation and testing of word frequency analysis
void overall_most_freq(max_heap hp) {
	std::cout << "*** Top 5 most frequent words: ***" << std::endl;
	//--- Add your code to print out the 5 most frequent words below:
	//If heap size is less than 5 print out all the words in the heap
	if (hp.size() <= 5) {
		for (int i = 0; i < hp.size()-1; i++) {
			std::cout << hp.find(i).word << std::endl;
		}
	} else {
	std::cout << hp.top() << std::endl;
	hp.delete_max();
	std::cout << hp.top() << std::endl;
	hp.delete_max();
	std::cout << hp.top() << std::endl;
	hp.delete_max();
	std::cout << hp.top() << std::endl;
	hp.delete_max();
	std::cout << hp.top() << std::endl;
	hp.delete_max();
	}
}

void at_least_length(max_heap hp, size_t num_letters) {
	cout << "*** Top 5 most frequent words with at least " 
		<< num_letters << " letters ***" << std::endl;
		
	//--- Add code to print out the 5 most common
	//--- words of length at least <num_letters>
	int count = 0;
	int inc = 0;	
	while(inc < hp.size() && count < 5) {
		inc++;
		if (hp.top().word.length() >= num_letters) {
			std::cout << hp.top() << std::endl;
			count++;
		}
		hp.delete_max();
	}
	
}

void starts_with(max_heap hp, char starts_with_letter) {
	cout << "*** Top 5 most frequent words that begin with " 
		<< starts_with_letter << " ***" << std::endl;
		
	//--- Add code to print out the 5 most common words
	//--- that start with the letter <starts_with_letter>
	int count = 0;
	int inc = 0;	
	while(inc < hp.size() && count < 5) {
		inc++;
		if (hp.top().word.substr(0,1)[0] == starts_with_letter) {
			std::cout << hp.top() << std::endl;
			count++;
		}
		hp.delete_max();
	}
	
	
}

void heap_tester() {	
	text_item temp;
	int heap_size = 10; //feel free to create heaps of other sizes when testing
	//cout << "How many items should be added to heap? ";
	//cin >> heap_size;
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
	load_bst("sample1.txt", tree); // create a bst from an input file.
	tree_tester(tree);			//sample2.txt contains a much bigger file
	
	//--- Part 3: word frequency analysis of text files
	text_analysis_tester(tree);

}
