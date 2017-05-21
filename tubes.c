/*	Program : Topologi Jaringan Komputer
	Kelompok 5 : 
	- Deni Martin (1500491)
	- Hazmi Ramadhan Adli (1301478)
	- M. Fathur Fawwaz (1505096)
	- M. Razi Iskandar (1501858)
	- Risa Ima Hafiqi (1507062)
	- Ziady Mubaraq (1504919)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

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

void addnode(graf* G, item data){
	int idnama = findnode(*G, data.nama);
	if(idnama==-1){
		(*G).simpul[(*G).jumlahsimpul].nama = data.nama;
		strcpy((*G).simpul[(*G).jumlahsimpul].jenis,data.jenis);
		(*G).jumlahsimpul++;
	}else{
		printf("\nPC/Hub dengan nama %c sudah ada",data.nama);
		getch();
	}
	
}

void addarc(graf* G, char awal, char akhir){
	int idxawal=findnode(*G, awal);
	int idxtujuan=findnode(*G, akhir);
	if(((*G).matriks[idxawal][idxtujuan]==1)&&((*G).matriks[idxtujuan][idxawal]==1)){
		printf("\nKabel LAN sudah terpasang");
		getch();
	}else if((idxawal!=-1)&&(idxtujuan!=-1)){
		(*G).matriks[idxawal][idxtujuan]=1;
		(*G).matriks[idxtujuan][idxawal]=1;
		printf("\nKabel LAN berhasil dipasang");
		getch();
	}else {
		if(idxawal==-1&&idxtujuan==-1){
			printf("\nPC/Hub %c dan %c tidak ditemukan\n",awal,akhir);
			printf("Silahkan periksa kembali");
		}else if(idxawal==-1){
			printf("\nPC/Hub %c tidak ditemukan\n",akhir);
			printf("Silahkan periksa kembali");
		}else{
			printf("\nPC/Hub %c tidak ditemukan\n",akhir);
			printf("Silahkan periksa kembali");
		} 
		getch();
	}
}

void setcolor(unsigned short color){
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hCon,color);
}

void head(){
	system("cls");
	printf("============================\n");
	printf(" Topologi Jaringan Komputer\n");
	printf("============================\n\n");
}

void menu_head(){
	printf("1. Materi Topologi\n");
	printf("2. Tambah PC/Hub\n");
	printf("3. Tambah Kabel LAN\n");
	printf("4. Tampilkan\n");
	printf("5. Periksa Topologi\n");
	printf("6. Keluar\n\n");
	printf("Masukan Pilihan : ");
}

void generate(graf G){
	int ring=0,bus=0,star=0,mesh=0,tree=0,linear=0,peer=0;
	if(G.jumlahsimpul!=0){
		system("cls");
		head();
		if(G.jumlahsimpul==2){
			//Pola Matriks Topologi Ring Ordo 2x2
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0){
					ring=1;
				}	
			}
			//Pola Matriks Topologi Linear Ordo 2x2
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0){
					linear=1;
				}	
			}
			//Pola Matriks Topologi Bus Ordo 2x2
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0){
					bus=1;
				}
			}
			//Pola Matriks Topologi Peer to Peer Ordo 2x2
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0){
					peer=1;
				}	
			}
		}else if(G.jumlahsimpul==3){
			//Pola Matriks Topologi Ring Ordo 3x3
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0){
					ring=1;
				}
			}
			//Pola Matriks Topologi Linear Ordo 3x3
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && 
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0)){
					linear=1;
				}
			}
			//Pola Matriks Topologi Bus Ordo 3x3
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0){
					bus=1;
				}
			}
			//Pola Matriks Topologi Star Ordo 3x3
			if(strcmp(G.simpul[0].jenis,"Hub")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0){
					star=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"Hub")==0 && strcmp(G.simpul[2].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && 
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0){
					star=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"Hub")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && 
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0){
					star=1;
				}
			}
		}else if(G.jumlahsimpul==4){
			//Pola Matriks Topologi Ring Ordo 4x4
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0)){
					ring=1;
				}
			}
			//Pola Matriks Topologi Bus Ordo 4x4
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0){
					bus=1;
				}
			}
			//Pola Matriks Topologi Mesh Ordo 4x4
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0){
					mesh=1;
				}
			}
			//Pola Matriks Topologi Star Ordo 4x4
			if(strcmp(G.simpul[0].jenis,"Hub")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0){
					star=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"Hub")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0){
					star=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"Hub")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==1 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0){
					star=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"Hub")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0){
					star=1;
				}
			}
			//Pola Matriks Topologi Linear Ordo 4x4
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0)){
					linear=1;
				}
			}
			//Pola Matriks Topologi Tree Ordo 4x4
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"Hub")==0 && strcmp(G.simpul[3].jenis,"Hub")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0)){
					tree=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"Hub")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"Hub")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0)){
					tree=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"Hub")==0 && strcmp(G.simpul[1].jenis,"Hub")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0)){
					tree=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"Hub")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"Hub")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0)){
					tree=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"Hub")==0 && strcmp(G.simpul[2].jenis,"Hub")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0)){
					tree=1;
				}
			}else if(strcmp(G.simpul[0].jenis,"Hub")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"Hub")==0 && strcmp(G.simpul[3].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && 
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0)){
					tree=1;
				}
			}
		}else if(G.jumlahsimpul==5){
			//Pola Matriks Topologi Tree Ordo 5x5
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"Hub")==0 && strcmp(G.simpul[4].jenis,"Hub")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==1 && G.matriks[4][2]==0 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==0 && G.matriks[4][2]==0 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==1 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==1 && G.matriks[4][2]==0 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0)){
					tree=1;
				}
			}
			//Pola Matriks Topologi Linear Ordo 5x5
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==0 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==0 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==0 && G.matriks[4][4]==0) ||
				   
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==0 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==1 && G.matriks[4][2]==1 && G.matriks[4][3]==0 && G.matriks[4][4]==0) ||
				   
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==1 && G.matriks[4][2]==0 && G.matriks[4][3]==1 && G.matriks[4][4]==0)){
					linear=1;
				}
			}
			//Pola Matriks Topologi Ring Ordo 5x5
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if((G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==0 && G.matriks[4][2]==0 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==1 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==0 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==0 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==1 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==0 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==1 && G.matriks[4][2]==1 && G.matriks[4][3]==0 && G.matriks[4][4]==0) ||
				   (G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==1 && G.matriks[4][2]==1 && G.matriks[4][3]==0 && G.matriks[4][4]==0)){
					ring=1;
				}
			}
			//Pola Matriks Topologi Bus Ordo 5x5
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==1 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==1 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0){
				   bus=1;	
				}
			}
			//Pola Matriks Topologi Star Ordo 5x5
			if(strcmp(G.simpul[0].jenis,"Hub")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==1 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==1 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==0 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==0 && G.matriks[4][2]==0 && G.matriks[4][3]==0 && G.matriks[4][4]==0){
				   star=1;	
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"Hub")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==1 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==0 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==1 && G.matriks[4][2]==0 && G.matriks[4][3]==0 && G.matriks[4][4]==0){
				   star=1;	
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"Hub")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==1 && G.matriks[0][3]==0 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==0 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==0 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==1 && G.matriks[4][3]==0 && G.matriks[4][4]==0){
				   star=1;	
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"Hub")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==1 && G.matriks[0][4]==0 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==1 && G.matriks[1][4]==0 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==0 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==0 && G.matriks[4][1]==0 && G.matriks[4][2]==0 && G.matriks[4][3]==1 && G.matriks[4][4]==0){
				   star=1;	
				}
			}else if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"Hub")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==0 && G.matriks[0][2]==0 && G.matriks[0][3]==0 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==0 && G.matriks[1][1]==0 && G.matriks[1][2]==0 && G.matriks[1][3]==0 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==0 && G.matriks[2][1]==0 && G.matriks[2][2]==0 && G.matriks[2][3]==0 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==0 && G.matriks[3][1]==0 && G.matriks[3][2]==0 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==1 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0){
				   star=1;	
				}
			}
			//Pola Matriks Topologi Mesh Ordo 5x5
			if(strcmp(G.simpul[0].jenis,"PC")==0 && strcmp(G.simpul[1].jenis,"PC")==0 && strcmp(G.simpul[2].jenis,"PC")==0 && strcmp(G.simpul[3].jenis,"PC")==0 && strcmp(G.simpul[4].jenis,"PC")==0){
				if(G.matriks[0][0]==0 && G.matriks[0][1]==1 && G.matriks[0][2]==1 && G.matriks[0][3]==1 && G.matriks[0][4]==1 &&
				   G.matriks[1][0]==1 && G.matriks[1][1]==0 && G.matriks[1][2]==1 && G.matriks[1][3]==1 && G.matriks[1][4]==1 &&
				   G.matriks[2][0]==1 && G.matriks[2][1]==1 && G.matriks[2][2]==0 && G.matriks[2][3]==1 && G.matriks[2][4]==1 &&
				   G.matriks[3][0]==1 && G.matriks[3][1]==1 && G.matriks[3][2]==1 && G.matriks[3][3]==0 && G.matriks[3][4]==1 &&
				   G.matriks[4][0]==1 && G.matriks[4][1]==1 && G.matriks[4][2]==1 && G.matriks[4][3]==1 && G.matriks[4][4]==0){
				   mesh=1;	
				}
			}
		}
		if(ring==1 && bus==1 && star==1 && mesh==1 && tree==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Mesh, Tree, Linear dan Peer To Peer");
		}else if(ring==1 && bus==1 && star==1 && mesh==1 && tree==1 && linear==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Mesh, Tree dan Linear");
		}else if(ring==1 && bus==1 && star==1 && mesh==1 && tree==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Mesh, Tree dan Peer To Peer");
		}else if(ring==1 && bus==1 && star==1 && mesh==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Mesh, Linear dan Peer To Peer");
		}else if(ring==1 && bus==1 && star==1 && tree==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Tree, Linear dan Peer To Peer");
		}else if(ring==1 && bus==1 && mesh==1 && tree==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Mesh, Tree, Linear dan Peer To Peer");
		}else if(ring==1 && star==1 && mesh==1 && tree==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Ring, Star, Mesh, Tree, Linear dan Peer To Peer");
		}else if(bus==1 && star==1 && mesh==1 && tree==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Bus, Star, Mesh, Tree, Linear dan Peer To Peer");
			
		}else if(ring==1 && bus==1 && star==1 && mesh==1 && tree==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Mesh dan Tree");
		}else if(ring==1 && bus==1 && star==1 && mesh==1 && linear==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Mesh dan Linear");
		}else if(ring==1 && bus==1 && star==1 && mesh==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Mesh dan Peer to peer");
		}else if(ring==1 && bus==1 && star==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Linear dan Peer to peer");
		}else if(ring==1 && bus==1 && star==1 && tree==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Tree dan Peer to peer");
		}else if(ring==1 && bus==1 && mesh==1 && tree==1 && linear==1){
			printf("Ini adalah Topologi Ring, Bus, Mesh, Tree dan Linear");
		}else if(ring==1 && bus==1 && mesh==1 && tree==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus, Mesh, Tree dan Peer to peer");
		}else if(ring==1 && star==1 && mesh==1 && tree==1 && peer==1){
			printf("Ini adalah Topologi Ring, Star, Mesh, Tree dan Peer to peer");
		}else if(ring==1 && star==1 && mesh==1 && tree==1 && linear==1){
			printf("Ini adalah Topologi Ring, Star, Mesh, Tree dan Linear");
		}else if(bus==1 && star==1 && mesh==1 && tree==1 && peer==1){
			printf("Ini adalah Topologi Bus, Star, Mesh, Tree dan Peer to peer");
		}else if(ring==1 && bus==1 && star==1 && peer==1 && linear==1){
			printf("Ini adalah Topologi Ring, Bus, Star, Peer to peer dan Linear");
		
		}else if(ring==1 && bus==1 && peer==1 && linear==1){
			printf("Ini adalah Topologi Ring, Bus, Peer to peer dan Linear");
		}else if(ring==1 && bus==1 && peer==1 && linear==1){
			printf("Ini adalah Topologi Ring, Bus, Peer to peer dan Linear");
			
		}else if(ring==1 && bus==1 && star==1){
			printf("Ini adalah Topologi Ring, Bus dan Star");
		}else if(ring==1 && bus==1 && mesh==1){
			printf("Ini adalah Topologi Ring, Bus dan Mesh");
		}else if(ring==1 && bus==1 && tree==1){
			printf("Ini adalah Topologi Ring, Bus dan Tree");
		}else if(ring==1 && bus==1 && linear==1){
			printf("Ini adalah Topologi Ring, Bus dan Linear");
		}else if(ring==1 && bus==1 && peer==1){
			printf("Ini adalah Topologi Ring, Bus dan Peer to peer");
		}else if(ring==1 && star==1 && bus==1){
			printf("Ini adalah Topologi Ring, Star dan Bus");
		}else if(ring==1 && star==1 && mesh==1){
			printf("Ini adalah Topologi Ring, Star dan Mesh");
		}else if(ring==1 && star==1 && tree==1){
			printf("Ini adalah Topologi Ring, Star dan Tree");
		}else if(ring==1 && star==1 && linear==1){
			printf("Ini adalah Topologi Ring, Star dan Linear");
		}else if(ring==1 && star==1 && peer==1){
			printf("Ini adalah Topologi Ring, Star dan Peer to peer");
		}else if(ring==1 && mesh==1 && bus==1){
			printf("Ini adalah Topologi Ring, Mesh dan Bus");
		}else if(ring==1 && mesh==1 && star==1){
			printf("Ini adalah Topologi Ring, Mesh dan Star");
		}else if(ring==1 && mesh==1 && tree==1){
			printf("Ini adalah Topologi Ring, Mesh dan Tree");
		}else if(ring==1 && mesh==1 && linear==1){
			printf("Ini adalah Topologi Ring, Mesh dan Linear");
		}else if(ring==1 && mesh==1 && peer==1){
			printf("Ini adalah Topologi Ring, Mesh dan Peer to peer");
		}else if(ring==1 && tree==1 && bus==1){
			printf("Ini adalah Topologi Ring, Tree dan Bus");
		}else if(ring==1 && tree==1 && star==1){
			printf("Ini adalah Topologi Ring, Tree dan Star");
		}else if(ring==1 && tree==1 && mesh==1){
			printf("Ini adalah Topologi Ring, Tree dan Mesh");
		}else if(ring==1 && tree==1 && linear==1){
			printf("Ini adalah Topologi Ring, Tree dan Linear");
		}else if(ring==1 && tree==1 && peer==1){
			printf("Ini adalah Topologi Ring, Tree dan Peer to peer");
		}else if(ring==1 && linear==1 && bus==1){
			printf("Ini adalah Topologi Ring, Linear dan Bus");
		}else if(ring==1 && linear==1 && star==1){
			printf("Ini adalah Topologi Ring, Linear dan Star");
		}else if(ring==1 && linear==1 && mesh==1){
			printf("Ini adalah Topologi Ring, Linear dan Mesh");
		}else if(ring==1 && linear==1 && tree==1){
			printf("Ini adalah Topologi Ring, Linear dan Tree");
		}else if(ring==1 && linear==1 && peer==1){
			printf("Ini adalah Topologi Ring, Linear dan Peer to peer");
		}else if(ring==1 && peer==1 && bus==1){
			printf("Ini adalah Topologi Ring, Peer to peer dan Bus");
		}else if(ring==1 && peer==1 && star==1){
			printf("Ini adalah Topologi Ring, Peer to peer dan Star");
		}else if(ring==1 && peer==1 && mesh==1){
			printf("Ini adalah Topologi Ring, Peer to peer dan Mesh");
		}else if(ring==1 && peer==1 && tree==1){
			printf("Ini adalah Topologi Ring, Peer to peer dan Tree");
		}else if(ring==1 && peer==1 && linear==1){
			printf("Ini adalah Topologi Ring, Peer to peer dan Linear");
		}else if(ring==1 && bus==1){
			printf("Ini adalah Topologi Ring dan Bus");
		}else if(ring==1 && star==1){
			printf("Ini adalah Topologi Ring dan Star");
		}else if(ring==1 && mesh==1){
			printf("Ini adalah Topologi Ring dan Mesh");
		}else if(ring==1 && tree==1){
			printf("Ini adalah Topologi Ring dan Tree");
		}else if(ring==1 && linear==1){
			printf("Ini adalah Topologi Ring dan Linear");
		}else if(ring==1 && peer==1){
			printf("Ini adalah Topologi Ring dan Peer to peer");
		}else if(bus==1 && star==1){
			printf("Ini adalah Topologi Bus dan Star");
		}else if(bus==1 && mesh==1){
			printf("Ini adalah Topologi Bus dan Mesh");
		}else if(bus==1 && tree==1){
			printf("Ini adalah Topologi Bus dan Tree");
		}else if(bus==1 && linear==1){
			printf("Ini adalah Topologi Bus dan Linear");
		}else if(bus==1 && peer==1){
			printf("Ini adalah Topologi Bus dan Peer to peer");
		}else if(star==1 && mesh==1){
			printf("Ini adalah Topologi Star dan Mesh");
		}else if(star==1 && tree==1){
			printf("Ini adalah Topologi Star dan Tree");
		}else if(star==1 && linear==1){
			printf("Ini adalah Topologi Star dan Linear");
		}else if(star==1 && peer==1){
			printf("Ini adalah Topologi Star dan Peer to peer");
		}else if(mesh==1 && tree==1){
			printf("Ini adalah Topologi Mesh dan Tree");
		}else if(mesh==1 && linear==1){
			printf("Ini adalah Topologi Mesh dan Linear");
		}else if(mesh==1 && peer==1){
			printf("Ini adalah Topologi Mesh dan Peer to peer");
		}else if(tree==1 && linear==1){
			printf("Ini adalah Topologi Tree dan Linear");
		}else if(tree==1 && peer==1){
			printf("Ini adalah Topologi Tree dan Peer to peer");
		}else if(linear==1 && peer==1){
			printf("Ini adalah Topologi Linear dan Peer to peer");
		}else if(ring==1){
			printf("Ini adalah Topologi Ring");
		}else if(bus==1){
			printf("Ini adalah Topologi Bus");
		}else if(star==1){
			printf("Ini adalah Topologi Star");
		}else if(mesh==1){
			printf("Ini adalah Topologi Mesh");
		}else if(tree==1){
			printf("Ini adalah Topologi Tree");
		}else if(linear==1){
			printf("Ini adalah Topologi Linear");
		}else if(peer==1){
			printf("Ini adalah Topologi Peer to Peer");
		}else{
			printf("Ini bukan topologi jaringan");
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
			if(strcmp(G.simpul[i].jenis,"Hub")==0){
				setcolor(207);printf("%c",G.simpul[i].nama);setcolor(7);printf(" ");
			}else{
				setcolor(159);printf("%c",G.simpul[i].nama);setcolor(7);printf(" ");
			}
			
		}
		printf("\n");
		for(i=0;i<G.jumlahsimpul;i++){
			if(strcmp(G.simpul[i].jenis,"Hub")==0){
				setcolor(207);printf("%c",G.simpul[i].nama);setcolor(7);printf(" ");
			}else{
				setcolor(159);printf("%c",G.simpul[i].nama);setcolor(7);printf(" ");
			}
			for(j=0;j<G.jumlahsimpul;j++){
				printf("%d ",G.matriks[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		setcolor(207);printf(" ");setcolor(7);printf(" = Hub\n");
		setcolor(159);printf(" ");setcolor(7);printf(" = PC");
	}else{
		printf("Graf masih kosong");
	}
}

int main(){
	graf G;
	item data;
	int menu1, menu2, menu3;
	char awal, akhir;
	createempty(&G);
	
	while(1){
		head();
		menu_head();
		scanf("%d",&menu1);
		switch(menu1){
			case 1:
				do{
					head();
					printf("1. Materi Topologi Ring\n");
					printf("2. Materi Topologi Bus\n");
					printf("3. Materi Topologi Star\n");
					printf("4. Materi Topologi Mesh\n");
					printf("5. Materi Topologi Tree\n");
					printf("6. Materi Topologi Linear\n");
					printf("7. Materi Topologi Peer to peer\n");
					printf("8. Kembali\n\n");
					printf("Masukan Pilihan : ");
					scanf("%d",&menu2);
					switch(menu2){
						case 1:
							system("cls");
							head();
							puts("Topologi Ring");
							puts("");
							puts("Syarat :");
							puts("- Terdiri dari minimal 2 Komputer");
							puts("- Tidak diperlukannya Hub");
							puts("");
							puts("Pengertian :");
							puts("  Topologi Ring adalah topologi jaringan yang rangkaiannya masing-masing");
							puts("tersambung ke dua titik yang lainnya, sehingga bisa membentuk jalur lingkaran");
							puts("yang menyerupai cincin. Kabel yang digunakan dalam topologi cincin merupakan");
							puts("kabel BNC, tidak mempunyai ujung maka tidak dibutuhkan terminator.");
							puts("");
							puts("Kelebihan :");
							puts("- Tidak diperlukannya host");
							puts("- Kecepatan dalam pengirimannya yang tinggi");
							puts("- Mudah dalam perancangan");
							puts("- Pengaksesan data yang optimal");
							puts("- Penggunaan kabel yang sedikit");
							puts("- Mampu melayani traffic yang padat.");
							puts("");
							puts("Kekurangan :");
							puts("- Kerusakan pada salah satu komputer dapat menyebabkan jaringan lumpuh");
							puts("- Memerlukan penanganan dan pengelolaan khusus bandles");
							puts("- Kinerja komunikasi bergantung dari banyaknya node");
							puts("- Tidak berfungsinya satu titik akan dapatmempengaruhi titik yang lain");
							puts("- Jika terjadi kerusakan di jaringan topologi ring sulit untuk diatasi.");
							getch();
						break;
						case 2:
							system("cls");
							head();
							puts("Topologi Bus");
							puts("");
							puts("Syarat :");
							puts("- Terdiri dari minimal 2 Komputer");
							puts("- Tidak diperlukannya Hub");
							puts("");
							puts("Pengertian :");
							puts("  Topologi bus adalah sebuah topologi yang media transmisinya menggunakan");
							puts("kabel tunggal atau kabel pusat  tempat yang menghubungkan client dan server.");
							puts("Topologi bus ini memakai kabel BNC dan di bagian kedua ujungnya harus diberi");
							puts("terminator. Sebenarnya Topologi ini cukup sederhana serta mudah ditangani,");
							puts("tetapi saat ini telah banyak ditinggalkan dikarenakan padatnya lalulintas");
							puts("data dan jika terdapat satu node yang rusak maka seluruh jaringan tidak");
							puts("bisa berfungsi.");
							puts("");
							puts("Kelebihan :");
							puts("- Topologi yang sederhana");
							puts("- Kabel yang digunakan sedikit untuk menghubungkan komputer-komputer");
							puts("- Biayanya lebih murah dibandingkan dengan susunan pengkabelan yang lain");
							puts("- Cukup mudah apabila kita ingin memperluas jaringan pada topologi bus.");
							puts("");
							puts("Kekurangan :");
							puts("- Sulit mengidentifikasi kesalahan jika jaringan mengalami gangguan");
							puts("- Lalu lintas data padat karena topologi bus menggunakan kabel terpusat");
							puts("- Jika terdapat salah satu client yang rusak, maka jaringan tidak berfungsi");
							puts("- Sebagai penguat sinyal dibutuhkan repeater untuk jarak jauh");
							puts("- Lebih lambat dibandingkan dengan topologi yang lain.");
							getch();
						break;
						case 3:
							system("cls");
							head();
							puts("Topologi Star");
							puts("");
							puts("Syarat :");
							puts("- Diperlukannya 1 Hub sebagai central node");
							puts("- Terdiri dari minimal 1 Hub dan 2 Komputer");
							puts("");
							puts("Pengertian :");
							puts("  Topologi star adalah bentuk topologi jaringan yang berupa konvergensi dari");
							puts("node tengah ke setiap node atau pengguna. Masing- masing workstation di");
							puts("hubungkan secara langsung ke Server atau Hub/Swich. Intinya topologi ini");
							puts("mengunakan Hub/Switch untuk menghubungkan dari komputer satu ke komputer yang");
							puts("lain. Hub/ Switch berfungsi untuk menerima sinyal-sinyal dari komputer dan");
							puts("meneruskan ke semua komputer yang terhubung dengan Hub/Swich tersebut.");
							puts("Topologi jaringan Star termasuk topologi jaringan dengan biaya menengah.");
							puts("");
							puts("Kelebihan :");
							puts("- Kerusakan pada satu saluran hanya akan mempengaruhi saluran itu saja");
							puts("- Tingkat keamanan termasuk tinggi");
							puts("- Tahan terhadap lalu lintas jaringan yang sibuk");
							puts("- Penambahan dan pengurangan station dapat dilakukan dengan mudah");
							puts("- Akses Kontrol terpusat");
							puts("- Kemudahan deteksi dan isolasi kesalahan/kerusakan pengelolaan jaringan");
							puts("- Paling fleksibel.");
							puts("");
							puts("Kekurangan :");
							puts("- Jika node tengah mengalami kerusakan, maka seluruh rangkaian akan berhenti");
							puts("- Boros dalam pemakaian kabel");
							puts("- HUB jadi elemen kritis karena kontrol terpusat");
							puts("- Peran hub sangat sensitif");
							puts("- Jaringan tergantung pada terminal pusat");
							getch();
						break;
						case 4:
							system("cls");
							head();
							puts("Topologi Mesh");
							puts("");
							puts("Syarat :");
							puts("- Terdiri dari minimal 4 Komputer");
							puts("- Tidak diperlukannya Hub");
							puts("");
							puts("Pengertian :");
							puts("  Topologi Mesh adalah bentuk hubungan yang semua perangkat/node saling");
							puts("terhubung satu sama lain. Pada topologi mesh ini setiap perangkat bisa");
							puts("berkomunikasi secara langsung dengan perangkat yang dituju. Topologi");
							puts("mesh ini hampir tidak pernah digunakan karena sulit ditangani dan");
							puts("juga boros kabel.");	
							puts("");
							puts("Kelebihan :");
							puts("- Proses pendeteksian dan pengisolasian kesalahan pada jaringan bisa");
							puts("  dilakukan dengan mudah karena konfigurasi jaringan menggunakan sistem");
							puts("  point to point");
							puts("- Data di hantarkan melalui jalur dedicated sehingga keamanan terjaga");
							puts("- Apabila terjadi ganguan diantara 2 jalur maka yang terkena imbasnya");
							puts("  hanya jalur yang bersangkutan saja.");
							puts("");
							puts("Kekurangan :");
							puts("- Banyaknya kabel yang diperlukan sehingga biayanya mahal");
							puts("- Proses instalasi lebih rumit dan ruang yang diperlukan lebih besar");
							getch();
						break;
						case 5:
							system("cls");
							head();
							puts("Topologi Tree");
							puts("");
							puts("Syarat :");
							puts("- Terdiri dari minimal 2 Komputer dan 2 Hub");
							puts("");
							puts("Pengertian :");
							puts("  Topologi Tree adalah topologi jaringan komputer yang merupakan kombinasi");
							puts("dari topologi Star dan Bus. Secara hirarki penyusunannya topologi tree ini");
							puts("merupakan kumpulan dari topologi star yang dihuhubungkan dengan topologi");
							puts("bus sebagai jalur tulang punggung atau backbone. Topologi pohon ini sering");
							puts("juga disebut dengan topologi bertingkat.");	
							puts("");
							puts("Kelebihan :");
							puts("- Cocok diterapkan pada jaringan komputer dengan skala besar");
							puts("- Pada topologi pohon ini memungkinkan penggunaan jaringan pont to point");
							puts("- Mudah dalam melakukan identifikasi jika terjadi kerusakan pada jaringan");
							puts("- Mudah dikembangkan.");
							puts("");
							puts("Kekurangan :");
							puts("- Pada area yang luas sulit untuk melakukan perawatan jaringan");
							puts("- Dapat terjadi tabrakan file data (collision)");
							puts("- Hub menjadi peran penting");
							puts("- Menggunakan biaya yang banyak karena menggunakan banyak kabel dan hub.");
							getch();
						break;
						case 6:
					       	system("cls");
					       	head();
							puts("Topologi Linear");
							puts("");
					       	puts("Syarat :");
					       	puts("- Terdiri dari minimal 2 Komputer");
					       	puts("- Tidak diperlukannya Hub");
					       	puts("");
					       	puts("Pengertian :");
					       	puts("  Topologi linier atau biasaya disebut topologi bus beruntut. Pada topologi ");
					       	puts("ini biasanya menggunakan satu kabel utama guna menghubungkan tiap titik ");
					       	puts("sambungan pada setiap komputer.");
					       	puts("");
					       	puts("Kelebihan :");
					       	puts("- Mudah dikembangkan.");
					       	puts("- Membutuhkan sedikit kabel.");
					       	puts("- Tidak memperlukan kendali pusat.");
					       	puts("");
					       	puts("Kekurangan :");
					       	puts("- Keamanan data kurang baik.");
					       	puts("- Memiliki kepadatan lalu lintas yang bisa dibilang cukup tinggi.");
					       	getch();
					    break;
					    case 7:
					       	system("cls");
					       	head();
							puts("Topologi Peer To Peer");
							puts("");
					       	puts("Syarat :");
					       	puts("- Terdiri dari 2 Komputer saja");
					       	puts("- Tidak diperlukannya Hub");
					       	puts("");
					       	puts("Pengertian :");
					       	puts("  Topologi peer to peer adalah topologi yg amat sangat sederhana sebab");
					       	puts("hanya memanfaatkan 2 buah computer/PC utk saling membuka. Pada topologi");
					       	puts("ini kebanyakan memakai satu kabel yg menghubungkan antar pc/komputer");
					       	puts("untuk proses pertukaran data.");
					       	puts("");
					       	puts("Kelebihan :");
					       	puts("- Biaya yang dibutuhkan sangat murah.");
					       	puts("- Masing-masing komputer dapat berperan sebagai client maupun server.");
					       	puts("- Instalasi jaringan yang cukup mudah.");
					       	puts("");
					       	puts("Kekurangan :");
					       	puts("- Keamanan pada topologi jenis ini bisa dibilang sangat rentan.");
					       	puts("- Sulit dikembangkan.");
					       	puts("- Sistem keamanan di konfigurasi oleh masing-masing pengguna.");
					       	puts("- Troubleshooting jaringan bisa dibilang rumit.");
					       	getch();
					    break;
						case 8:
							
						break;
						default:
							printf("\nPilihan tidak tersedia!");
							getch();
						break;
					}	
				}while(menu2!=8);
			break;
			case 2:
				if(G.jumlahsimpul<5){
					do{
						head();
						printf("1. Tambah PC\n");
						printf("2. Tambah Hub\n");
						printf("3. Kembali\n\n");
						printf("Masukan Pilihan : ");
						scanf("%d",&menu3);
						switch(menu3){
							case 1:
								system("cls");
								head();
								printf ("Masukan nama PC : ");
								scanf(" %c",&data.nama);
								strcpy(data.jenis,"PC");
								addnode(&G,data);	
								menu3=3;
							break;
							case 2:
								system("cls");
								head();
								printf ("Masukan nama Hub : ");
								scanf(" %c",&data.nama);
								strcpy(data.jenis,"Hub");
								addnode(&G,data);
								menu3=3;
							break;
							case 3:
								
							break;
							default:
								printf("\nPilihan tidak tersedia!");
								getch();
							break;
						}	
					}while(menu3!=3);
				}else{
					printf("\nMaaf maksimal PC/Hub adalah 5");
					getch();
				}
			break;
			case 3:
				head();
				printf("Tambah kabel LAN dari : ");
				scanf(" %c",&awal);
				printf("Sambungkan pada       : ");
				scanf(" %c",&akhir);
				addarc(&G,awal,akhir);
			break;
			case 4:
				system("cls");
				head();
				printmatriks(G);
				getch();
			break;
			case 5:
				system("cls");
				head();
				generate(G);
				getch();
			break;
			case 6:
				return 0;
			break;
			default:
				printf("\nPilihan tidak tersedia!");
				getch();
			break;
		}
	}
}
