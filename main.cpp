#include "lex.h"

int main()
{
	Lex lex("1.txt");
	token tk = ERR_TOKEN;
	while (tk.type != EOF_TOKEN.type)
	{
		tk = lex.get_token();
		if (tk.type == VARNAME)
			printf("���� ���Ƶ�ַ�� %p\n", tk.value.var_name);
		else if (tk.type == INT_NUM)
			printf("���� %d\n", tk.value.int_value);
		else if (tk.type == REAL_NUM)
			printf("������ %lf\n", tk.value.real_value);
		else if (tk.type == STRING)
			printf("�ַ��� ���ַ���ַ�� %p\n", tk.value.var_name);
		else
			printf("���ͣ�%d %d\n", tk.type, tk.value.sym_name);
	}

	system("pause");
	return 0;
}
