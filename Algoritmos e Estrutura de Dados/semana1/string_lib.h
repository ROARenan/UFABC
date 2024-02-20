#ifndef STRING_LIB_H
#define STRING_LIB_H

typedef struct {
  char* data; 
  int length; 
} String;

String* string_create(char* data, int len);
void string_destroy(String* str);
void string_print(String* str);
String* string_reverse(String* str);
void string_append(String *str1, String* str2);


#endif