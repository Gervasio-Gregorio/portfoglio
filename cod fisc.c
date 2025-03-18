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
void print();

//variabili globali
char surrname[3]= {'X','X','X'}, na[3]= {'X','X','X'}, anno[2], month, giorno[2], city[4], check_code, codfin[11];
int ann, day, febb=28, nday;
int main()
{
    int i;
	printf("calcolo codice fiscale\n");
	//surr();
	//name();
	//yea();
	//mon();
	//day_gend();
	i = cy();
	if(i == 1)
	{
		printf("errore citta non presente");
		return 1;
	}
	//chk();
	//print();
	return 0;
}

//funzioni
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
	for(int x=0; x<3; x++)
	{
	    codfin[x]=toupper(surrname[x]);
	    printf("%c\n", codfin[x]);
	}
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
	for(int x=3; x<6; x++)
	{
	    codfin[x]=toupper(na[x]);
	    printf("%c\n", codfin[x]);
	}
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
	if(ann%400)
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
}

int cy()
{
	int i = 1, x = 0;
	char reeder[20], input[20], output[4], ciao;
	char city[4];
	FILE *file;
	file = fopen("comuni.txt", "r");
	if (file == NULL)
	{
		printf("Errore nell'apertura del file.\n");
		return 1;
	}
	printf("Inserire il nome del comune: ");
	scanf(" %s", input);
	
	for(int x=0; x<5; x++)
	{
	    fscanf(file, "%s %s\n", reeder, output);
	    printf("%s\n",input);
	    printf("%s\n",reeder);
	    printf("%s\n",output);
		if(strcmp(input,reeder) == 0)
		{
		    printf("codice trovato: %s", output);
		    i=0;
			break;
		}
	}
	fclose(file);
	return i;
}

void chk()
{
    
}