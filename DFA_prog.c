#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// ��������� ��� ��� ������ ��� ������� ��� ������
int CheckString(char *string,char *alphabet);


	int main()
	{
		FILE *fp; // Pointer �������
   		int states; // ������ �����������
   		int i = 1; // ������ ����������� �������
   		int k = 0; // Counter ��� ��� ���������� ��������� ����� ������� cs,tr,nw
  		int trans = 0; // ������ ����������
  		int fl_counter = 0; // Counter ��� �� ���������� ��� ��������� ��� ���������
		char line[256]; // ������� ��� ���������� ��������� ���� �� �������� �������
  		char start; // ������ ���������
  		char *alphabet; //������������ ���� ������ ���� �� ������� ��� ��������
  		char *final; // ������� �����������
  		char input[30]; // ������� ��� ������
  		
		//cs = �������� ���������(1� �����),tr = ���� ���������(2� �����),nw = ��� ���������(3� �����)
		char *cs,*tr,*nw;
  		
  		// ������� �������
   		fp = fopen("C:\\Users\\Christos\\Desktop\\dfa.txt","r");
   		
   		//������� ��� ����� �������� ���� �� ������� ��� �������
   		if(fp == NULL)
   		{
   			perror("Error opening file");
      		return -1;
		}
   		
	//�������� ������� ������-������
    while (fgets(line, sizeof(line), fp))
	 {

 		if(i == 1) //�������� 1�� ������� - ����������� ���������
      	{
      		states = atoi(line); // ��������� char �������� �� integer
      		if(states >= 10) // ������� ��� �� ������ ��� �����������
      		{
      			printf("The automatic must have under ten(<10) states!");
      			return 1;
			}
		}
 		
 		if(i == 2) //�������� 2�� ������� - �������� ���������
      	{
      		int cnt = 0; //������������ �������
      		int j = 0; //������������ ���������� ��� ���������� ��� ������
      		
      		// ��� ����������� ��� ������� �������('\n') �������� ��� ������
      		while(line[j] != '\n') 
      		{
				if(line[j] != ' ') //�� �� �������� ����������� ��� �����(' ')
				{
					cnt++; //��������� ��� �������
					fl_counter++; //Counter ��� �� ���������� ��� ��������� ��� ���������
				}	
				j++; // ������ ��� ���������� �������� ��������� ��� ������	
			}
			
			alphabet = (char *)malloc(cnt * sizeof(char)); //���������� �������� ���� ��� ��� ��������
			
			j=0; cnt = 0;
			// ��� ����������� ��� ������� �������('\n') �������� ��� ������
      		while(line[j] != '\n') 
      		{
			  	if(line[j] != ' ') //�� �� �������� ����������� ��� �����(' ')
					alphabet[cnt++] = line[j]; // ��������� �� �������� ��� ��������� ���� ������	
				j++; // ������ ��� ���������� �������� ��������� ��� ������	
			}
						
			if(cnt >= 10) // ������� ��� �� ������ �������� 
			{
				printf("The alphabet must have under ten(<10) different symbols!");
      			return 2;
			}
			
			trans = states * fl_counter; // ������ ��� �����������
    		
			cs = (char *)malloc(trans * sizeof(char)); //���������� �������� ���� ��� ��� ��������� ����������� (1� �����)
    		tr = (char *)malloc(trans * sizeof(char)); //���������� �������� ���� ��� ��� ����� ���������� (2� �����)
    		nw = (char *)malloc(trans * sizeof(char)); //���������� �������� ���� ��� ��� ���� ����������� (3� �����)
		}
      	
      	if(i==3) //�������� 3�� ������� - ������ ���������
      		start = line[0]; // ������������ ��� ������ ���������
 	
 		if(i==4) //�������� 4�� ������� - ������� �����������
 		{
 			
 			int cnt = 0; //������������ �������
      		int j = 0; //������������ ���������� ��� ���������� ��� ������
      		
      		// ��� ����������� ��� ������� �������('\n') �������� ��� ������
      		while(line[j] != '\n')
      		{	
				if(line[j] != ' ')
				{ cnt++; } //��������� ��� �������
				
				j++; // ������ ��� ���������� �������� ��������� ��� ������			
			}
 			
 			// ���������� ����� �������� �� ���� �� ������ ��� ������� ����������� 
			final = (char *)malloc(cnt * sizeof(char));
			
			int k=0; j=0; //������������ ����������
			
			// ��� ����������� ��� ������� �������('\n') �������� ��� ������
			while(line[j] != '\n') 
      		{
				if(line[j] != ' ')
				{ final[k++] = line[j]; } //��������� �� ������ ��� ������� �����������
				
				j++; // ������ ��� ���������� �������� ��������� ��� ������		
			}
		}
 
	 
	 	// ���� �������� ������ ���������� ���� ��� ������� ��� ��� 4� ������ ��� ����,
	 	// ��� ������������ �� �������� ���������� ����� 3 �������(cs,tr,nw)
 		if(i > 4)
 		{	
			int j = 0;
 			while(line[j] != '\n') 
      		{
				if(line[j] != ' ') //�� �� �������� ����������� ��� �����(' ')
				{
					if(j == 0) //��� ����������� ��� 1� ��������
						cs[k] = line[j]; //������������ �� �������� ��� ��� ��������� �����������
					if(j == 2) //��� ����������� ��� 2� �������� 
						tr[k] = line[j]; //������������ �� �������� ��� ��� ����� ����������
					if(j == 4) //��� ����������� ��� 3� �������� 
						nw[k] = line[j]; //������������ �� �������� ��� ��� ���� ������������				
				}
				
					//��� �������� ���� ��������� ������ ��� ������ ��� ���������� ��� �������� ������� break
					if(trans+4 == i && j == 4)
					break;
				
				j++; // ������ ��� ���������� �������� ��������� ��� ������	line
			}
			
			k++; //������ ������� ��� ���� ������� cs,tr,nw ���� �� ���������� ���������
		}

		i++; // �������� �� ���� ��� ������ ������� ���� �� �������� ��� �������
    }



	char ch;
	do{
	fflush(stdin); // ����������� �� buffer
	
	//���������� ��� ���� ������� ��� ��� ������
    printf("Give the input:");
    fgets(input,30,stdin);

    
    // ��������� �� � ������������ ������� ����� ��������
    // ������� �� �� ��������
	if(CheckString(input,alphabet) == 0)
	  {
			printf("The input is wrong!");
			return 1;		
	  }
	  
    
    int length_in = strlen(input); //����� �������
    char final_state = start; // ������������� ��� ������ ��������� �� ��� ������ ���������
    int flag = 0; // flag ��� ������
    
    
    //�������� ��� loop �� ���� �� ����� �������
    for(i=0;i<length_in-1;i++)
	{
		//������������ ����������
		int j = 0;
		flag = 0;
		
		/* �������� ��� loop �� ���� �� ������ ��� �����������, ���� ���� ���
		���������� ��� ��������� ��� ������������ ��� �� ����� � ��������
		�������� �� flag = 1 ���� ���� �� ��� ����xo, �� ������� ����
		������ �� �� flag == 1 ��� ���� ������� break ���� ������ ��� ���� ���
		��������� ��� ������������ ��� ����������� �� �� ������� ������ ������� */
		for(j=0;j<trans;j++)
		{
			if(final_state == cs[j] && input[i] == tr[j])
			{
				//printf("final_state: %c == cs[j]: %c\n",final_state,cs[j]);
				//printf("input:       %c == tr[j]: %c\n",input[i],tr[j]);
				printf("INPUT -> %c\nCURRENT_STATE -> q%c\n",input[i],final_state);
				final_state = nw[j];
				printf("NEW_STATE    -> 'q%c'\n\n",final_state);
				flag = 1;
			}
			
			if(flag==1)
			break;
		}		
	}
	
	fflush(stdin); // ����������� �� buffer
	
	flag = 0; //������������� �� flag
	
	/* �������� ��� loop �� �� ����� ������� ���� ��� ������� �����������
	 ��� ����������� ��� ��������� ��� ������ ��� ��� ������ ���� ��
	 ����� �� ����� �������� ������ ���������*/
	for(i=0;i<strlen(final);i++)
	{
		if(final_state == final[i])
		flag = 1;	
	}    
	
	//��� ����� �������� ��������� 
	if(flag == 1)
	{
		printf("--------------------------");
		printf("\nThe Input is acceptable!\n");
		printf("The Final State is q%c\n",final_state);
		printf("--------------------------");
	}
	else
	{
		printf("------------------------------");
		printf("\nThe Input is NOT acceptable!\n");
		printf("The Final State is q%c\n",final_state);
		printf("------------------------------");
	}
	
	//������ ��� ������ �� ����� �� ��������� ���� ������ �� ��� ������
	printf ("\nDo you want to continue y/n: ");
	ch = getchar();
	system("cls");
	}while(ch == 'y' || ch == 'Y');
    
	// ������������� ��� ����� ��� ���������������
    free(final);
    free(alphabet);
    free(cs);
    free(tr);
    free(nw);
    
    fclose(fp); //��������� �� ������
    
	return 0;
}


	/*��������� �� ��� ����� ���������� �� � ������� ��� ������
	����� ����� �� ���� �� �������� ��� dfa */
	int CheckString(char *string,char *alphabet)
	{
		int i = 0, j = 0; //Counter �������
		int flag = 0; // flag ���� �� ���������� �� �� string ������������ ��� ��������
		int s1 = strlen(string); // ����� �������
		int s2 = strlen(alphabet); // ����� ���������
		    	
		//�������� ��� loop ��� ���� ������ ��� �������
		for(i=0;i<s1-1;i++)
    	{
    		flag = 0; //������������� �� 0 ���� ���� 
    		// ��� ���� ������ ������� ��������� ��� �� �������� ��� ���������
    		for(j=0; j<s2; j++)
    		{	
    			if(string[i] == alphabet[j]) //��� �� ������ ������� ������������ ��� ��������
    			flag = 1; //������������� �� flag �� 1	
			}
			
			if (flag == 0) //��� �� ������ ������� ��� ������������ ��� ��������
			return 0; //������������ 0 ��� ������������ ��� ���������
		}
		
		return 1; //����� ������������ 1 � ������������ ������� ����� �����
	}
