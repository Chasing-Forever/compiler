#include "lex.h"

int main(int argc, char ** argv)
{
	if (argc <= 1)
	{
		fprintf(stderr, "Fetal: No input file.\n");
		exit(-1);
	}
	else if (argc >= 3)
	{
		printf("Warning: the argument after %s will be ignored.\n", argv[1]);
	}
	try
	{
		Lex lex(argv[1]);
		token tk = ERR_TOKEN;
		while (tk.type != EOF_TOKEN.type)
		{
			tk = lex.get_token();
			lex.Symbol_Token();
			switch(tk.type)
			{
			    case TYPENAME:   printf("�����ͱ�ʾ���� ���ͱ�ţ�%d\n", tk.value.sym_name); break;
				case VARNAME:    printf("���������� ������ַ��%p\n", tk.value.var_name); break;
				case INT_NUM:    printf("�������� %d\n", tk.value.int_value); break;
				case REAL_NUM:   printf("���������� %lf\n", tk.value.real_value); break;
				case STRING:     printf("���ַ����� ���ַ���ַ��%p\n", tk.value.str_name); break;
				case DELIMITER:  printf("���ָ����� ���ͱ�ţ�%d\n", tk.value.sym_name); break;
				case CONTROLLER: printf("�����Ʒ��� ���ͱ�ţ�%d\n", tk.value.sym_name); break;
				case OPERATOR:   printf("��������� ���ͱ�ţ�%d\n", tk.value.sym_name); break;
				case ERR_TYPE:   printf("��Ч�ַ���\n"); break;
				case EOF_TYPE:   printf("�ļ�������\n"); break;
			}
		}
		return 0;
	}
	catch (File_Error)
	{
		fprintf(stderr, "Fetal: Cannot open file %s.\n", argv[1]);
		exit(-1);
	}
}
