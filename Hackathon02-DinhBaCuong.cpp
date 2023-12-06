#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct contact{
		int id;
		char name[50];
		char phone[12];
		char address[50];
		int status;
	};


void printMenu(){
	printf("********MENU*********\n");
	printf("1 In toan bo danh sach co o trong mang\n");
	printf("2 Them contact moi vao vi tri cuoi cung\n");
	printf("3 Cap nhap thong tin contact\n");
	printf("4 Chon contact muon xoa\n");
	printf("5 Thuc hien chuc nang sap xep va in ra\n");
	printf("6 Thuc hien chuc nang tim kiem theo ten va in ra thong tin contact\n");
	printf("7 Thuc hien chuc nang tim kiem theo status va in ra thong tin contact\nNhap su lua chon");
}
typedef struct contact contact;
void input(contact *temp){
    printf("nhap id:");
    scanf("%d",&temp->id);
    printf("nhap ten: ");
    getchar();
    gets(temp->name);
    printf("nhap so dien thoai: ");
    getchar();
    gets(temp->phone);
    printf("nhap dia chi: ");
    getchar();
    gets(temp->address);
    printf("nhap trang thai: ");
    scanf("%d",&temp->status);
}
void output( contact *temp){
    printf("ID:%d, ten :%s, sdt :%s, dia chi:%s, trang thai:%d\n",temp->id, temp->name, temp->phone, temp->address, temp->status);
}

int main(){
	int n,i;
	int index =2;
	int count;
	contact contactList[2]=
	{
		{1,"cuong","0123456789","10MoLao",0},
		{2,"duong","0987654321","20MoLao",1}		
	};
	
	int choice;
	do{
	printMenu();
	getchar();
	scanf("%d",&choice);
	switch(choice){
	case 1:
     	for (i=0;i<index;i++) {
            printf("%d:",i+1);
            output(&contactList[i]);
            printf("\n");
            }
		break;
	case 2:
		input(&contactList[index]);
        index++;
		break;
	case 3:
		count=0;
           	int updateContact;
            printf("Nhap vao ID contact can cap nhap:");
            scanf("%d",&updateContact);
            for (i=0;i<index;i++) {
               if (contactList[i].id == updateContact)
                {input(&contactList[i]);
				count =1;
				}
    			}
    		if(count==0){
    		    printf("Khong tim thay\n");
			}
		break;
	case 4:
		count=0;
        int deleteContact;
        printf("Nhap vao ID contact can xoa:");
        scanf("%d",&deleteContact);
        for (i=0;i<index;i++) {
        if (contactList[i].id == deleteContact){
        for (int j=i;j<index-1;j++){
            contactList[i] = contactList [i+1];	
            count=1;
		}
	    }
        }
        if(count==0){
    		printf("Khong tim thay\n");
		}
        index--;
		break;
	case 5:
		break;
	case 6:
		break;
	case 7:
		int statusContact ;
        printf("Nhap trang thai 0 hoac 1 cua Contact can tim :");
        scanf("%d",&statusContact);
		for (i=0;i<index;i++){
			if(contactList[i].status == statusContact){
				output(&contactList[i]);	
			}else if(contactList[i].status != statusContact){
				printf("So trang thai nhap khong hop le\n");
			}
		}
		break;
    }
    }while(1==1);
    
    return 0;
}



