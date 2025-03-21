#include <stdio.h>
#include <string.h>
#include <ctype.h>

//dichiarazzione funzzioni
void name();
void surr();
void yea();
void mon();
void day_gend();
int cy();
void chk();
int valore_pari(char x);
int valore_dispari(char x);
void print();

//variabili globali
char surrname[3]= {'X','X','X'}, na[3]= {'X','X','X'}, an[2], da[2], month, city[4], check_code, fin_code[16];
int ann, day, febb=28, nday;

int main()
{
	printf("calcolo codice fiscale\n");
	//apertura delle funzzioni
	surr();
	name();
	yea();
	mon();
	day_gend();
	int i = cy();
	if(i == 1)
	{
		printf("errore citta non presente");
		return 1;
	}
	chk();
	print();
	return 0;
}

//funzioni
void print()
{
	printf("%s", fin_code);
}

void surr()
{
	char surr[]="Wolfeschlegelsteinhausenbergerdorff", voc[3]= {'X','X','X'};
	int l, x, y, nc=0, pos1=0, pos2=0, ncon=0;
	printf("inserire il cognome: ");
	scanf("%s",surr);
	l=strlen(surr);
	for(x=0; x<l; x++)
	{
		switch (surr[x])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		{
			break;
		}
		default:
		{
			ncon++;
			break;
		}
		}
	}
	for(x=0; x<l; x++)
	{
		switch (surr[x])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			if(pos2<3)
			{
				voc[pos2]=surr[x];
				pos2++;
			}
			break;
		default:
			nc++;
			if(nc==1 || nc==2 || nc==3)
			{
				surrname[pos1]=surr[x];
				pos1++;
			}
			break;
		}
	}
	while(pos1<3 && pos1<=l && ncon<l)
	{
		surrname[pos1]=voc[y];
		y++;
		pos1++;
	}
	fin_code[0]=toupper(surrname[0]);
	fin_code[1]=toupper(surrname[1]);
	fin_code[2]=toupper(surrname[2]);
}

void name()
{
	char name[]="Hubert Blaine", voc[3]= {'X','X','X'};
	int l, x, y=0, nc=0, pos1=0, pos2=0, ncon=0, lever=4;
	printf("inserire il nome: ");
	scanf("%s",name);
	l=strlen(name);
	for(x=0; x<l; x++)
	{
		switch (name[x])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
		{
			break;
		}
		default:
		{
			ncon++;
			break;
		}
		}
	}
	if(ncon<=3)
	{
		lever=2;
	}
	for(x=0; x<l; x++)
	{
		switch (name[x])
		{
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u':
			if(pos2<3)
			{
				voc[pos2]=name[x];
				pos2++;
			}
			break;
		default:
		{
			nc++;
			if(nc==1 || nc==3 || nc==lever)
			{
				na[pos1]=name[x];
				pos1++;
			}
			break;
		}
		}
	}
	while(pos1<3 && pos1<=l && ncon<l)
	{
		na[pos1]=voc[y];
		y++;
		pos1++;
	}
	fin_code[3]=toupper(na[0]);
	fin_code[4]=toupper(na[1]);
	fin_code[5]=toupper(na[2]);
}

void yea()
{
	int x;
	printf("inserire l'anno di nascita: ");
	scanf("%d",&ann);
	while(ann>2026 || ann<=1907)
	{
		printf("l'anno non C( valido reinserirlo: ");
		scanf("%d",&ann);
	}
	if(ann%400 == 0)
	{
		febb=29;
	}
	if(ann%4 && ann%100!=0)
	{
		febb=29;
	}
	if(ann<2000)
	{
		ann-=1000;
	}
	else
	{
		ann-=2000;
	}
	for(x=900; x>=0; x-=100)
	{
		if(ann>x)
		{
			ann-=x;
			break;
		}
		else if(ann==x)
		{
			ann=0;
			break;
		}
	}
	if(ann<10 && ann > 0)
	{
		fin_code[6]='0';
		fin_code[7]=(ann) + '0';
	}
	else if(ann == 0)
	{
		fin_code[6]='0';
		fin_code[7]='0';
	}
	else
	{
		fin_code[6] = (ann / 10) + '0';
		fin_code[7] = (ann % 10) + '0';
	}
}

void mon()
{
	char lett[12]= {'A','B','C','D','E','H','L','M','P','R','S','T'};
	int m, len[12]= {31,febb,31,30,31,30,31,31,30,31,30,31};
	printf("inseisci il mese numerale: ");
	scanf("%d",&m);
	while(m<1 || m>12)
	{
		printf("mese non valido deve essere compreso tra 1 e 12: ");
		scanf("%d",&m);
	}
	month=lett[m-1];
	nday=len[m-1];
	fin_code[8]=toupper(month);
}

void day_gend()
{
	int gio;
	char gen = 'm';
	printf("inserire il giorno di nascita: ");
	scanf(" %d",&gio);
	while(gio<1 || gio>nday)
	{
		printf("giorno non valido deve essere compreso tra 1 e %d: ",nday);
		scanf(" %d",&gio);
	}
	printf("inserire genere M/F: ");
	scanf(" %c",&gen);
	while(gen!='m' && gen!='M' && gen!='f' && gen!='F')
	{
		printf("genere non riconosciuto inserire M/F: ");
		scanf(" %c",&gen);
	}
	if(gen=='f' || gen=='F')
	{
		gio+=40;
	}
	day = gio;
	if(day<10 && day > 0)
	{
		fin_code[9]='0';
		fin_code[10]=(day) + '0';
	}
	else if(day == 0)
	{
		fin_code[9]='0';
		fin_code[10]='0';
	}
	else
	{
		fin_code[9] = (day / 10) + '0';
		fin_code[10] = (day % 10) + '0';
	}
}

int cy()
{
	int i = 1;
	char red[20], input[20], pippo[4];
	FILE *file;
	file = fopen("comuni.txt", "r");
	if (file == NULL) {
		printf("Errore nell'apertura del file.\n");
		return 1;
	}
	printf("Inserire il nome del comune: ");
	scanf("%s", input);
	while (fscanf(file, "%s %s %s\n", pippo, red, city) == 3 && !feof(file))
	{
		if (strcmp(input, red) == 0)
		{
			i = 0;
			break;
		}
	}
	fclose(file);
	fin_code[11]=city[0];
	fin_code[12]=city[1];
	fin_code[13]=city[2];
	fin_code[14]=city[3];
	return i;
}

void chk() {
	char contr[26] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
		'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
		'U', 'V', 'W', 'X', 'Y', 'Z'
	};
	int tot_disp = 0, tot_par = 0, tot = 0;
	for (int x = 0; x < 15; x++) {
		if (x % 2 == 0)
			tot_disp += valore_dispari(fin_code[x]);
		else
			tot_par += valore_pari(fin_code[x]);
	}
	tot = (tot_par + tot_disp) % 26;
	check_code = contr[tot];
	fin_code[15] = check_code;
}

int valore_dispari(char x)
{
	switch (x) {
	case 'A':
		return 1;
	case 'B':
		return 0;
	case 'C':
		return 5;
	case 'D':
		return 7;
	case 'E':
		return 9;
	case 'F':
		return 13;
	case 'G':
		return 15;
	case 'H':
		return 17;
	case 'I':
		return 19;
	case 'J':
		return 21;
	case 'K':
		return 1;
	case 'L':
		return 0;
	case 'M':
		return 5;
	case 'N':
		return 7;
	case 'O':
		return 9;
	case 'P':
		return 13;
	case 'Q':
		return 15;
	case 'R':
		return 17;
	case 'S':
		return 19;
	case 'T':
		return 21;
	case 'U':
		return 1;
	case 'V':
		return 0;
	case 'W':
		return 5;
	case 'X':
		return 7;
	case 'Y':
		return 9;
	case 'Z':
		return 13;
	case '0':
		return 1;
	case '1':
		return 0;
	case '2':
		return 5;
	case '3':
		return 7;
	case '4':
		return 9;
	case '5':
		return 13;
	case '6':
		return 15;
	case '7':
		return 17;
	case '8':
		return 19;
	case '9':
		return 21;
	default:
		printf("Errore dispari");
		return 1;
	}
}

int valore_pari(char x)
{
	switch (x) {
	case 'A':
		return 0;
	case 'B':
		return 1;
	case 'C':
		return 2;
	case 'D':
		return 3;
	case 'E':
		return 4;
	case 'F':
		return 5;
	case 'G':
		return 6;
	case 'H':
		return 7;
	case 'I':
		return 8;
	case 'J':
		return 9;
	case 'K':
		return 10;
	case 'L':
		return 11;
	case 'M':
		return 12;
	case 'N':
		return 13;
	case 'O':
		return 14;
	case 'P':
		return 15;
	case 'Q':
		return 16;
	case 'R':
		return 17;
	case 'S':
		return 18;
	case 'T':
		return 19;
	case 'U':
		return 20;
	case 'V':
		return 21;
	case 'W':
		return 22;
	case 'X':
		return 23;
	case 'Y':
		return 24;
	case 'Z':
		return 25;
	case '0':
		return 0;
	case '1':
		return 1;
	case '2':
		return 2;
	case '3':
		return 3;
	case '4':
		return 4;
	case '5':
		return 5;
	case '6':
		return 6;
	case '7':
		return 7;
	case '8':
		return 8;
	case '9':
		return 9;
	default:
		printf("Errore pari");
		return 1;
	}
}