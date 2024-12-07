# Canonical Huffman Code Compression and Decompression

## Overview 
This is a better version of Huffman Code and was developed in C++ for compressing and decompressing text file as an assignment for Data Structure & Algorithm Course, University of Science - VNUHCM  

### Features
- **Compression**: Compress text file into binary file.  
- **Decompression**: Restore original text from compressed file.  
- Supports all ASCII characters, including letters (a-z, A-Z), digits (0-9), and symbols.

---

## Table of Contents  
1. [Installation](#installation)  
2. [Usage](#usage)  
    - [Compression](#compression)  
    - [Decompression](#decompression)  
3. [How It Works](#how-it-works)  
4. [Binary File Format](#binary-file-format)  
5. [Future enhancements](#future-enhancements)  
6. [Contact Information](#contact-information)
7. [Reference](#reference)
---

## Installation  

1. Clone the repository
   ```bash  
   git clone https://github.com/InfiniteVoidLoop/Huffman-Code
   cd huffman-code  

2. Compile the source code to exe
    ```bash
    g++ *.cpp -o 
    
## Usage  

### Compression  

### Decompression

## How It Works  

1. **Frequency Analysis**:  
   The program reads the input file and calculates the frequency of each unique character.  

2. **Huffman Tree Construction**:  
   Using the calculated frequencies, a standard Huffman binary tree is constructed. This tree assigns unique Huffman codes to each character based on their frequency, following standard Huffman encoding principles.

3. **Canonical Huffman Code**:  
   From the bit length of each character, the program generates Canonical Huffman Codes and assign code for each character. 

5. **Compression**:  
   The program replaces characters in the input text with their respective canonical Huffman binary codes.

6. **Decompression**:   
   The binary file only stores the bit length of each character which have already been sorted, after that we recover the Canonical Huffman Code and then build a tree in order to restore the text file efficiently.

---
## Binary File Format
When saving Canonical Huffman-encoded data into a binary file during compression, the file follows a specific structure. Below is the structure of the saved Huffman binary file:


| **Name**            | **Size**   | **Description**                              |
|---------------------|------------|-----------------------------------------------|
| **Table_size**      | 1 byte     | Size of the table                             |
| **Character 1**     | 1 byte     | Character 1                                    |
| **Code length 1**   | 1 byte     | Length of the code for character 1        |
| **Character 2**     | 1 byte     | Character 2                                    |
| **Code length 2**   | 1 byte     | Length of the code for character 2        |
|   **...**           |   ...       |          ...                                     |
| **Encoded Binary Data** | -       | Encoded Huffman data                         |
| **Padding**         | 1 byte     | Number of bits used for alignment            |

---

## Future Enhancements  

1. **Support for Larger Input Data**:  
   Enhance the program to handle very large files by implementing streaming-based compression and decompression, allowing the program to process data incrementally rather than loading entire files into memory.  


2. **Graphical User Interface (GUI)**:  
   Create a user-friendly GUI to make the program accessible to users without requiring terminal/command-line knowledge.

3. **Extend to Support Dynamic Huffman Coding**:  
   Implement dynamic Huffman coding techniques to allow the system to adapt encoding strategies on the fly, based on changing input data patterns during runtime.

4. **Optimize Compression Ratios**:  
   Further optimize the Huffman encoding logic to achieve even better compression ratios by experimenting with alternative variations of the Huffman coding algorithm or hybrid compression strategies.

5. **Support for Compressing Multiple Files**:
    Currently, the program compresses and decompresses a single file at a time. 

---


## Contact Information

If you have any questions, feedback, bug reports or feature requests feel free to reach out:

- **Email**: [23120155@student.hcmus.edu.vn](mailto:23120155@student.hcmus.edu.vn)  
- **GitHub**: [https://github.com/InfiniteVoidLoop](https://github.com/InfiniteVoidLoop)  
- **Facebook**: [@DangPhuc](https://www.facebook.com/pg.bas.ket/)  

We welcome collaboration, contributions, and any suggestions you may have!

---
## References

The following references and resources were used in the development of this project:

1. [Huffman Coding - Wikipedia](https://en.wikipedia.org/wiki/Huffman_coding)  
2. [Canonical Huffman Codes Explained - GeeksforGeeks](https://www.geeksforgeeks.org/canonical-huffman-coding/)  
3. [ChatGPT - OpenAI](https://openai.com/)

We'd like to give credit to these resources for their valuable insights and technical foundations.
