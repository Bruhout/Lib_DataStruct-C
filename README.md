# Lib_DataStruct-C
Right now only has linked lists implemented, soon adding Hash table in conjunction with linked lists and more.

To get started:
For linked list:
   1. Include the linked_list.h header file
   2. Link against linked_list.a in your compiler (On arm64 computers)
   3. Otherwise, build the main.c file with the following command. (Source code contained in main.c.)

         gcc -o linked_list.o linked_list.c -c

   4. Now link against linked_list.o.

   5 .You have successfully learned how to use linked_list in your own project.

For hash table:
   1. Follow the above steps, as hash_table does require the linked_list library.
   2. Also include hash_table.h into your project.
   3. Build the hash_table.c file with the following command.

         gcc -o hash_table.o hash_table.c -c

   4. Now, assuming linked_list.h, linked_list.o, hash_table.h and hash_table.o are in the working directory, compile against both linked_list.o and hash_table.o



Version 2.0
1. Added a custom print function.
2. Added more documentation.

Version 3.0
1. Added ability to create linked list from integer array.
2. Added ability to populate integer array from linked list.

Version 4.0
1. Added Hash Tables
