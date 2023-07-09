#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <numeric>

// Class representing a node in the directory tree
struct Node {
	// Pointer to the parent in the tree
	Node* parent;
	// The size of this node
	int size;
	// Bool indicating if this node is a directory or not
	bool isDir;
	// The name of this node
	std::string name;

	// All of the children of this node
	std::vector<Node> children;

	// Function that returns the parent (returning ourselves if the parent happens to be null (root's parent is root))
	Node* safeParent() {
		if(parent == nullptr) return this;
		return parent;
	}

	// Function which dumps the directory structure to standard out 
	void dump(int level = 0) {
		// Add indentation
		std::cout << std::string(level, ' ') 
		// Print the name
			<< " - " << name;
		// Print if its a dir or a size
		if(size == 0) std::cout << " (dir)";
		else std::cout << " (file, size=" << size << ")";
		std::cout << "\n";

		// Dump the children
		for(auto& c: children)
			c.dump(level + 1);
	}

	// Function which propagates directory size information through the tree
	int propigateSizes(){
		// If this is a file just return our size
		if(size > 0) return size; 

		// Otherwise recursively sum the sizes of the children
		size = 0;
		for(auto& c: children)
			size += c.propigateSizes();

		return size;
	}

	// Function which sums all of the sizes which are less than 100k
	int sumSizesLessThan100k(){
		// If our size is less than 100k add it to the size
		int size = 0;
		if(isDir && this->size < 100'000) size += this->size;

		// Recursively sum the matching sizes in the children
		for(auto& c: children)
			size += c.sumSizesLessThan100k();

		return size;
	}

	// Convert all of the directory sizes to a vector
	void enumerateDirectorySizes(std::vector<int>& sizes){
		if(isDir) sizes.push_back(size);

		for(auto& c: children)
			c.enumerateDirectorySizes(sizes);
	}
};



int main() {
	// File connection
	std::ifstream fin("input.txt", std::ios::binary);

	// Create the tree root
	Node tree { nullptr, 0, true, "/"};
	// Pointer to our current directory
	Node* currentDir = &tree;

	// Bool indicating if we should be in command mode or not
	bool commandMode = true;
	// While there is still data in the file
	while(fin){
		// If we are in command mode (line starts with $s)
		if(commandMode){
			// Read the dollar sign and the command
			char dollarSign;
			std::string command, arg;
			fin >> dollarSign >> command;
			// Break the loop if we are out of data
			if(!fin) break;

			// If the command is cd...
			if(command == "cd"){
				// Read in the directory we should change to
				fin >> arg;

				// Root changes the current directory to the root
				if(arg == "/")
					currentDir = &tree;
				// ".." changes the directory to the parent
				else if(arg == "..")
					currentDir = currentDir->safeParent();
				// Otherwise a name moves into the directory of that name in the current directory
				else for(auto& c: currentDir->children)
					if(c.name == arg){
						currentDir = &c;
						break;
					}
			// List switches us out of command mode
			} else if (command == "ls")
				commandMode = false;

		// If we are not in command mode (listing out directory data)
		} else {
			// Read in the first word
			std::string command;
			fin >> command;
			// Break if we are out of data
			if(!fin) break;

			// If the lines starts with a $
			if(command == "$"){
				// Step back in the stream so that the $ will be read next and switch to command mode
				fin.seekg(-2, std::ios::cur);
				commandMode = true;

			// If the line starts with dir
			} else if (command == "dir"){
				// Read in the name
				std::string name;
				fin >> name;

				// Create a new directory as a child of the current directory
				currentDir->children.push_back({currentDir, 0, true, name});

			// If the line starts with a number
			} else {
				// Convert the number to an int
				int size;
				std::stringstream s(command);
				s >> size;

				// Read in the file's name
				std::string name;
				fin >> name;

				// Create a new file as a child of the current directory
				currentDir->children.push_back({currentDir, size, false, name});
			}
		}
	}

	//Propagate the size information up through the tree
	tree.propigateSizes();

	// Part 1
	// Sum all of the sizes that are less than 100k
	std::cout << tree.sumSizesLessThan100k() << std::endl;


	// // Part 2
	// // Convert all of the sizes in the array to a vector
	// std::vector<int> sizes;
	// tree.enumerateDirectorySizes(sizes);
	// // Sort the vector so that it is in increasing order
	// std::sort(sizes.begin(), sizes.end());

	// // Calculate how much space needs to be freed
	// auto unused = 70000000 - tree.size;
	// auto needed = 30000000 - unused;

	// // Find the smallest size that is greater than the needed size
	// for(auto size: sizes)
	// 	if(size >= needed){
	// 		std::cout << "The smallest directory we can delete is of size: "
	// 			<< size << std::endl;
	// 		break;
	// 	}
}