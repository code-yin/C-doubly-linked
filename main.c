#include <stdio.h>
#include <stdlib.h>
#include "my_dlist.h"

int main() {
	DList* list = create_list();
	
	if (list == NULL) {
		printf("内存不足\n");
		return 1;
	}
	printf("创建成功 (初始长度: %d)\n", list->len);
	
	printf("\n--- 执行尾插: 10, 20, 30 ---\n");
	push_back(list, 10);
	push_back(list, 20);
	push_back(list, 30);
	print_list(list); 
	
	printf("\n--- 执行头插: 5 ---\n");
	push_front(list, 5);
	print_list(list);
	
	printf("\n--- 执行尾插: 40 ---\n");
	push_back(list, 40);
	print_list(list);
	
	printf("\n--- 链表长度: %d ---\n", get_length(list));
	
	free_list(list);
	
	list = NULL; 
	
	printf("结束\n");
	
	return 0;
}
