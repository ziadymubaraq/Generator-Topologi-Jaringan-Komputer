#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char nama;
	char jenis[50];
}item;

typedef struct{
	item simpul[50];
	int matriks[50][50];
	int jumlahsimpul;
}graf;

void createempty(graf* G){
	(*G).jumlahsimpul=0;
	int i,j;
	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			(*G).matriks[i][j]=0;
		}
	}
}

void addnode(graf* G, item data){
	(*G).simpul[(*G).jumlahsimpul].nama = data.nama;
	strcpy((*G).simpul[(*G).jumlahsimpul].jenis,data.jenis);
	(*G).jumlahsimpul++;
}

int findnode(graf G, char nama){
	int hasil=-1;
	int status=0;
	int i=0;
	while((status==0)&&(i<G.jumlahsimpul)){
		if(G.simpul[i].nama==nama){
			status=1;
			hasil=i;
		}else{
			i++;
		}
	}
	return hasil;
}


void addarc(graf* G, char awal, char akhir){
	int idxawal=findnode(*G, awal);
	int idxtujuan=findnode(*G, akhir);
	if((idxawal!=-1)&&(idxtujuan!=-1)){
		(*G).matriks[idxawal][idxtujuan]=1;
	}else{
		if(idxawal==-1){
			printf("data simpul %c tidak ada \n",awal);
			printf("cek simpul!!! \n");
		}
		if(idxtujuan==-1){
			printf("data simpul %c tidak ada \n",akhir);
			printf("cek simpul!!! \n");
		}
		system("pause");
	}
}

void head(){
	system("cls");
	printf("============================\n");
	printf("          Generator\n");
	printf(" Topologi Jaringan Komputer\n");
	printf("============================\n");
}

void menu_head(){
	printf("1. Tambah PC/Router\n");
	printf("2. Tambah Kabel LAN\n");
	printf("3. Tampilkan\n");
	printf("4. Generate Topologi\n");
	printf("5. Keluar\n\n");
	printf("Masukan Pilihan : ");
}

void generate(graf G){
	if(G.jumlahsimpul!=0){
		system("cls");
		head();
		int i,j;
		printf("  ");
		for(i=0;i<G.jumlahsimpul;i++){
			printf("%c ",G.simpul[i].nama);
		}
		printf("\n");
		for(i=0;i<G.jumlahsimpul;i++){
			printf("%c ",G.simpul[i].nama);
			for(j=0;j<G.jumlahsimpul;j++){
				printf("%d ",G.matriks[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		if(G.jumlahsimpul==2){
			if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[1][0]==1 && G.matriks[1][1]==0){
				printf("Ini adalah topologi ring");
			}else{
				printf("Ini bukan topologi jaringan");
			}
		}else if(G.jumlahsimpul==3){
			//some code	
		}else if(G.jumlahsimpul==4){
			//some code	
		}else if(G.jumlahsimpul==5){
			//some code	
		}
	}else{
		printf("Graf masih kosong");
	}
}

void printmatriks(graf G){
	if(G.jumlahsimpul!=0){
		int i,j;
		printf("  ");
		for(i=0;i<G.jumlahsimpul;i++){
			printf("%c ",G.simpul[i].nama);
		}
		printf("\n");
		for(i=0;i<G.jumlahsimpul;i++){
			printf("%c ",G.simpul[i].nama);
			for(j=0;j<G.jumlahsimpul;j++){
				printf("%d ",G.matriks[i][j]);
			}
			printf("\n");
		}
	}else{
		printf("Graf masih kosong");
	}
}

int main(){
	graf G;
	item data;
	int menu1, menu2;
	char awal, akhir;
	createempty(&G);
	
	while(1){
		menu_utama:
		head();
		menu_head();
		scanf("%d",&menu1);
		switch(menu1){
			case 1:
				do{
					head();
					printf("1. Tambah PC\n");
					printf("2. Tambah Router\n");
					printf("3. Kembali\n\n");
					printf("Masukan Pilihan : ");
					scanf("%d",&menu2);
					switch(menu2){
						case 1:
							system("cls");
							head();
							printf ("Masukan nama PC : ");
							scanf(" %c",&data.nama);
							strcpy(data.jenis,"PC");
							addnode(&G,data);	
							menu2=3;
						break;
						case 2:
							system("cls");
							head();
							printf ("Masukan nama Router : ");
							scanf(" %c",&data.nama);
							strcpy(data.jenis,"Router");
							addnode(&G,data);
							menu2=3;
						break;
						case 3:
							
						break;
						default:
							printf("\nPilihan tidak tersedia!");
							getch();
						break;
					}	
				}while(menu2!=3);
			break;
			case 2:
				head();
				printf("Tambah kabel LAN dari : ");
				scanf(" %c",&awal);
				printf("Sambungkan pada       : ");
				scanf(" %c",&akhir);
				addarc(&G,awal,akhir);
			break;
			case 3:
				system("cls");
				head();
				printmatriks(G);
				getch();
			break;
			case 4:
				generate(G);
				getch();
			break;
			case 5:
				return 0;
			break;
			default:
				printf("\nPilihan tidak tersedia!");
				getch();
			break;
		}
	}
}
