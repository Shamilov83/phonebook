/*SvSpisok.h*/
#ifndef heder_file
#define heder_file


typedef struct Node{
	char surname[20];
	int value;
	struct Node *next;
}Spisok;

void menu(void);
void menu_add_elem(void);
Spisok *menu_find_elem(void);
void menu_delet_elem(void);

Spisok *creat(char* surname,int num);
void add_element_end(char*, int,Spisok*);
Spisok *add_element(char*, int,Spisok*);
void output_sp(Spisok*);
Spisok *find_element(char*,Spisok*);
Spisok *delet_element(char *,Spisok*);
#endif
