# Huffman Code Compression and Decompression

## Overview 
This project was developed in C++ for compressing and decompressing text file as an assignment for Data Structure & Algorithm Course, University of Science - VNUHCM

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
5. [Enhancements](#enhancements)  
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
    cd src
    g++ *.cpp -o main

## Usage  
 - Note that the input file should be in the same directory as the executable file `main`, which is located in the `src` folder.
 - If you want file in another directory, you can use the full path to the file.
### Compression  
- To compress a text file, run the following command:  
    ```bash
      ./main <input file1> <input file2>

      
    ```
    - For compressing a file: `<input file1>` should end with `.txt` and `<input file2>` should end with `.bin`.

### Decompression
- To decompress a binary file, run the following command:  
    ```bash
      ./main <input file1> <input file2>


    ```
    - For decompressing a file: `<input file1>` should end with `.bin` and `<input file2>` should end with `.txt`.

## How It Works  

1. **Frequency Analysis**:  
   The program reads the input file and calculates the frequency of each unique character.  

2. **Huffman Tree Construction**:  
   Using calculated frequencies, builds a binary tree structure where characters with lower frequencies are given longer binary codes.

3. **Encoding**:  
   Each character is mapped to its respective unique binary code based on the Huffman tree.  

4. **Compression**:  
   The program replaces characters in the input text with their respective Huffman binary codes to save space.  

5. **Decompression**:  
   The program reconstructs the original text by recovering the huffman tree from the code table at file header.

---
## Binary File Format
When saving Huffman-encoded data into a binary file during compression, the file follows a specific structure. Below is the structure of the saved Huffman binary file:


| **Name**            | **Size**   | **Description**                              |
|---------------------|------------|-----------------------------------------------|
| **Table_size**      | 1 byte     | Size of the table                             |
| **Character 1**     | 1 byte     | Character 1                                    |
| **Code length 1**   | 1 byte     | Length of Huffman Code for character 1        |
| **Code 1**          | 4 bytes    | Huffman Code for character 1                  |
| **Character 2**     | 1 byte     | Character 2                                    |
| **Code length 2**   | 1 byte     | Length of Huffman Code for character 2        |
| **Code 2**          | 4 bytes    | Huffman Code for character 2                  |
|   **...**           |   ...       |          ...                                           |
| **Encoded Binary Data** | -       | Encoded Huffman data                         |
| **Padding**         | 1 byte     | Number of bits used for alignment            |

---

## Enhancements
We've already improved this project by using Canonical Huffman Tree which can encode file in fewer bits. With knowledge of the canonical Huffman algorithm, it is then possible to recreate the entire table (symbol and code values) from just the bit-lengths.

There is a case when the depth of Huffman Tree is high (more than 32), so the previous version can face limitations when dealing with large code in the table. However, it is a pieace of cake when using Canonical Huffman Tree and save only the bit-lengths in the table.  

Explore our Canonical Huffman Code with our [Canonical Huffman Coding Project on GitHub](https://github.com/InfiniteVoidLoop/Canonical-Huffman-Code)

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
