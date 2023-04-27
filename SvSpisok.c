/*SvSpisok.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SvSpisok.h"

extern Spisok *head;
extern Spisok *sel_element;

/*инициализация списка*/
Spisok *creat(char* surname,int num)
{
//выделение пямяти под корень списка
Spisok *tmp = (Spisok*)malloc(sizeof(Spisok));
//присваивание значения узлу
strcpy(tmp -> surname, surname);
tmp -> value = num;
//присваивание указателя на следующий элемент значения
tmp -> next = NULL;

return (tmp);
}


/*добавление узла в конец списка*/
void add_element_end(char* surname, int num, Spisok *head)
{
//выделение памяти под корень списка
Spisok *tmp = (Spisok*)malloc(sizeof(Spisok));
//присваивание значения узлу
strcpy(tmp -> surname,surname);
tmp -> value = num;
//присвоение указателю на следующее значение NULL
tmp -> next = NULL;
//присваивание новому указателю указателя head
//присваивание выполняется для того чтобы не потерять указатель на голову списка
Spisok *p = head;
//сдвиг указателя р в самый конец первоначального списка
while(p -> next != NULL)
p = p -> next;
//присваивание указателю р -> next значение указателя tmp(созданный новый узел)
p -> next = tmp;
}

/*добавление узла*/
Spisok *add_element(char* surname, int num, Spisok *head)
{
Spisok *tmp = head;

if(tmp == NULL)
	tmp = creat(surname,num);
else
	add_element_end(surname,num,head);

return tmp;
}

//вывод элементов списка
void output_sp(Spisok *head)
{

Spisok *tmp = head;

	while(tmp != NULL){
	//вывод значения узла
	printf("%s",tmp -> surname);
	printf("%d\n", tmp -> value);
	
	//сдвиг указателя к следующему узлу
	tmp = tmp -> next;
	}	
}


/*главное меню*/
void menu(void)
{
  int num_menu;
  int flag;

 while(!flag)
 {
  printf("Выберите действие 1:ввод данных, 2:поиск, 3:удаление элемента, 4:выход \n");
  scanf("%d",&num_menu);

        switch(num_menu)
          {
                  case 1: menu_add_elem();
                  break;
                  case 2: menu_find_elem();
                  break;
                  case 3: menu_delet_elem();
                  break;
                  case 4: flag = 1;
		  break;
                  default: printf("Вы ввели неверное число! Попробуйте еще раз \n");
                  break;
          }
  }

 }

/*меню добавления элементов*/
void menu_add_elem(void)
{
char surname[20];
unsigned int number_fon;

printf("Введите фамилию: ");
scanf("%s", surname);
printf("Введите номер телефона: ");
scanf("%d", &number_fon);
head = add_element(surname,number_fon,head);
output_sp(head);
}

/*меню поиска*/
Spisok *menu_find_elem(void)
{
Spisok *tmp = NULL;
char surname[20];

printf("Введите фамилию для поиска: \n");
scanf("%s",surname);
tmp = find_element(surname,head);
return tmp;
}

/*меню удаления элемента*/
void menu_delet_elem(void)
{
char mn[1];
char srnm[20];
Spisok *tmp = NULL;
printf("%s","Введите фамилию: ");
scanf("%s",srnm);
find_element(srnm,head);
printf("%s","Удалить элемент y/n \n");
scanf("%s",mn);
if(!strncmp(mn,"y",1)) head = delet_element(srnm,head);
}


/*Функция поиска по фамилии*/
Spisok *find_element(char*surname,Spisok*head)
{
//Присваивание новому указателю tmр указателя head, p-NULL
Spisok *tmp = head;
//если список не пуст, выход 
if(head == NULL) return NULL;
//поиск указателя на искомый элемент
	while(tmp)
	{

		if(!strcmp(tmp -> surname, surname))
		{
			printf("%s %s %d %s", tmp -> surname," ",tmp -> value,"\n");
			return tmp;
		}
		else
		{
			tmp = tmp -> next;
		}
	}
//если искомый элемент первый
if(tmp == head) return head;

//если в списке нет искомого элемента, то возвращаем NULL
	if(!tmp)
	{
		printf("%s"," Объект не найден!\n");
		return NULL;
	}
}




/*функция удаления элемента*/
Spisok *delet_element(char *surname,Spisok *head)
{
//Присваивание новому указателю tmр указателя head, p-NULL
Spisok *tmp = head, *p = NULL;
//Проверка списка на пустоту
if(head == NULL)
return NULL;
//если список не пуст, поиск указателя на искомый элемент
while(tmp && !strcmp(tmp -> surname,surname))
{
p = tmp;
tmp = tmp ->next;
}
//если удаляемый элемент первый
if(tmp == head)
{
free(head);
return tmp -> next;
}
//если в списке нет искомого элемента, то возвращаем первоначальный список
if(!tmp)
return head;
//присваивание новому указателю указателя tmp
p -> next = tmp -> next;
//освобождение памяти для указателя tmp
free(tmp);
return head;
}

