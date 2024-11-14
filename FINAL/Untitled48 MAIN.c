#include<stdio.h>
#include<string.h>
#include<time.h>
#include<windows.h>
// admin username admin.
// admin password 123.
void viewinven();
void additem();
void deleteitem();
void update();
void diszero();
void dispro();
void sells1();
void customer();
void login(char* namee,char* passe);
void registeration(char* name,char* pass);
typedef struct {
	int id;
	char name[50];
	double price;
	double dis;
	int quan;
}Item;
typedef struct{
	char name[50];
	double price;
	char buyer[50];
}sells;
char mybuyer[50];// global variable i used it in generate reciept
double total=0;
int main(){
	int n1;
	char n2[10];
	char namee[50],passe[50],name[50],pass[50];
	printf("\n\t\t\t\t\t\x1b[47m\x1b[30m LOGIN/REGISTRATION \x1b[0m");
	while(1){
	printf("\n\t\t\t\t\t1) LOGIN:\n\t\t\t\t\t2) REGISTRATION: \n\t\t\t\t\t\x1b[32mEnter Your Choice: \x1b[0m");
	scanf("%d",&n1);
	getchar();//to discard newline it comes when we press enter. if we dont put getchar in registration both question will come together.
	if(n1==1){
		login(namee,passe);
		break;
	}
	else if(n1==2){
		registeration(name,pass);
		break;
	}
	else{
		printf("\n\t\t\t\t\t\x1b[31mWRONG INPUT!!\x1b[0m");
	}	
	}
	
	
	return 0;
}
void login(char* namee,char* passe){
char content[1000],name[50],pass[50];
int n;
char n1[50];
char n2[50];
FILE* fptr;

printf("\t\t\t*****************************************************************");
printf("\n\t\t\t\t1) ADMIN \n\t\t\t\t2) CUSTOMER:\n\t\t\t\t\x1b[32mEnter Your Choice: \x1b[0m");
scanf("%d",&n);
getchar();
int found=0;
if(n==2){
	while(found!=1){
	printf("\n\t\t\t\tEnter Username: ");
	fgets(namee,50,stdin);
	namee[strcspn(namee,"\n")]='\0';
	printf("\n\t\t\t\tEnter Password: ");
	fgets(passe,50,stdin);
	passe[strcspn(passe,"\n")]='\0';
    fptr=fopen("customer.txt","r");
if(fptr!=NULL){
	while(fgets(content,sizeof(content),fptr)){// we write stdin in fgets when we read input directly from keyboard but when write fptr means pointer of file to get input from file.
	    sscanf(content, "%s %s",name,pass);// seperates the content into name and pass
		if(strcmp(namee,name)==0 && strcmp(passe,pass)==0){
			strcpy(mybuyer,namee);
			printf("\n\t\t\t\x1b[32mWELCOME CUSTOMER!!\x1b[0m\n");
			found=1;
			fclose(fptr);
			break;
		}
	}
	
	if(found==1){
		customer();
	}
	else{
		printf("\n\t\t\t\x1b[31mWRONG CREDENTIALS!!\x1b[0m\n");
	}
	

}
else{
	printf("\n\t\t\tFile Open Unsuccessful!! \n");
}
}	
	}
    	

    

else if(n==1){
	
	while(1){
	printf("\n\t\t\t\tEnter Username: ");
	scanf("%s",&n1);
	printf("\n\t\t\t\tEnter Password: ");
	scanf("%s",&n2);
	getchar();
	if(strcmp(n1,"admin")==0 && strcmp(n2,"123")==0){
		printf("\n\t\t\t\t\x1b[32m WELCOME ADMIN!!\x1b[0m \n");
		printf("\n\t\t\t\t\x1b[36m Enter Any Key To Continue\x1b[0m");
		getchar();
		while(1){
	int input;
	printf("\n\t\t\t*******************\x1b[47m\x1b[30m WELCOME TO MAIN MENU \x1b[0m********************** \n\n");
	printf("\t\t\t\t\x1b[36m[1] View Inventory\x1b[0m \n");
	printf("\t\t\t\t\x1b[36m[2] Add An Input A New Product Record\x1b[0m \n");
	printf("\t\t\t\t\x1b[36m[3] Delete Product\x1b[0m \n");
	printf("\t\t\t\t\x1b[36m[4] Update Product Details\x1b[0m \n");
	printf("\t\t\t\t\x1b[36m[5] Display Products With Zero Quantity\x1b[0m \n");
	printf("\t\t\t\t\x1b[36m[6] Display Product Sells\x1b[0m \n");
	printf("\t\t\t\t\x1b[36m[7] Display Products With Discounts\x1b[0m \n");
	printf("\t\t\t\t\x1b[36m[8] Exit Program.\x1b[0m \n");
	printf("\t\t\t\t\x1b[32mEnter Your Choice.\x1b[0m ");
	scanf("%d",&input);
	getchar();
	if(input==1){
	viewinven();
	}
	else if(input==2) {
	additem();
	}
	else if(input==3){
	deleteitem();
	}
	else if(input==4){
	update();
	}
	else if(input==5){
	diszero();
	}
	else if(input==6){
	sells1();
	}
	else if(input==7){
	dispro();
	}
	else if(input==8){
		return;
	}	
	
	}
	
		
	}
	else{
		printf("\n\t\t\t\x1b[31mADMIN FAILED TO LOGIN\x1b[0m\n");
	}	
	}
		
	}
	


}
/* Here i created void fucntion because i dont need to return it to read data from file. actually i created a function here which handles the transfer 
of data in file so in main whenever i want to use this data i will call function and i will use it for example read it append more data etc. Also in function parameters
i used (char* name) actually this pointer also behave as array notation like this [] but you need to define size in fgets so that it completes in array form 
both will work.*/
void registeration(char* name,char* pass){
    char namee[50],passe[50];
	FILE* fptr;
	printf("\t\t\t*****************************************************************");
	printf("\n\t\t\t\tSet Username: ");
	fgets(name,50,stdin);
	name[strcspn(name,"\n")]='\0';
	printf("\n\t\t\t\tSet Password: ");
	fgets(pass,50,stdin);
	pass[strcspn(pass,"\n")]='\0';// count strlen before specified character here \n
	fptr=fopen("customer.txt","a");
	if(fptr!=NULL){
	fprintf(fptr, "%s %s\n",name,pass);
	printf("\n\t\t\t\x1b[32mRegisteration Successful!!\x1b[0m\n");	
	}
	else{
		printf("\n\t\t\t\x1b[31mRegisteration Unsuccessful!!\x1b[0m\n");
	}
	fclose(fptr);
	login(namee,passe);
}
void viewinven(){
	printf("----------------------------------------------------------------------------------");
	Item item;
	FILE*fptr;
	fptr=fopen("inven.txt","rb");
	if(fptr!=NULL){
		while(fread(&item,sizeof(item),1,fptr)){
			printf("\n\n\t\t\t\tItem ID: %d\n \n\t\t\t\tItem Name: %s\n \n\t\t\t\tItem Price: %.2lf\n \n\t\t\t\tDiscounts: %.2lf%%\n \n\t\t\t\tQuantity: %d",item.id,item.name,item.price,item.dis,item.quan);
			printf("\n------------------------------------------------------------------------");
		}
		fclose(fptr);
	}
	else{
		printf("\t\t\tFile open Unsuccessful \n");
	}
	
}
void additem(){
	int valid=0;
	Item item;
	char choice[5];
	printf("\n---------------------------------------------------------------------------\n\n");
	printf("\t\t\t******************\x1b[47m\x1b[30m WElCOME TO THE INVENTORY \x1b[0m**********************\n");
	FILE*fptr;
	fptr=fopen("inven.txt","ab");
	while(1){
		while(valid==0){
	printf("\n\t\t\tEnter Product ID: ");
	valid=scanf("%d",&item.id);
	if(valid<1){
		printf("\n\t\t\t\x1b[31mInvalid ID, Please Enter Correct ID\x1b[0m");
		while(getchar()!='\n');
	}
		}
	getchar();
	printf("\n\t\t\tEnter Product Name: ");
	fgets(item.name,50,stdin);
	item.name[strcspn(item.name,"\n")]='\0';
	printf("\n\t\t\tEnter Product Price: ");
	scanf("%lf",&item.price);
	printf("\n\t\t\tEnter Discounts On Product: ");
	scanf("%lf",&item.dis);
	printf("\n\t\t\tEnter Product Quantity: ");
	scanf("%d",&item.quan);
	if(fptr!=NULL){
	fwrite(&item,sizeof(item),1,fptr);	
	printf("\n\t\t\t Add More Products?: ");
	scanf("%s",&choice);
	if(strcmp(choice,"y")!=0&&strcmp(choice,"yes")!=0){
		fclose(fptr);
		break;
	   }
	 }
	 else{
	 	printf("\t\t\tFile Opening Unsuccessful \n");
	 }
	 valid=0;
	}
	
		
}
void deleteitem(){
	Item item;
	int found=0;
	char namedelete[20];
		printf("\n\t\t\t\tItem Name To Delete: ");
		fgets(namedelete,sizeof(namedelete),stdin);
		namedelete[strcspn(namedelete,"\n")]='\0';
		FILE*fptr;
		FILE*fptr1;
		fptr=fopen("inven.txt","rb");
		fptr1=fopen("invennew.txt","wb");
		if(fptr!=NULL&&fptr1!=NULL){
		while(fread(&item,sizeof(item),1,fptr)){
			if(strcmp(item.name,namedelete)!=0){
				fwrite(&item,sizeof(item),1,fptr1);
			}
			else{
				found=1;
			}
		}
		fclose(fptr);
		fclose(fptr1);	
		
		if(found==1){
			remove("inven.txt");
			rename("invennew.txt","inven.txt");
			printf("\n\t\t\t\x1b[32mProduct Deleted successfully\x1b[0m \n");
		}
		else{
			printf("\n\t\t\t\t\x1b[31mProduct Not Found\x1b[0m \n");
			remove("invennew.txt");
		}
	}
		else{
			printf("\n\t\t\t\tFile Open Unsuccessful \n");
		}
}
void update(){
	int valid=0;
	char name[50];
	int found=0;
	Item item;
	FILE*fptr;
	fptr=fopen("inven.txt","rb+");
	printf("\n\t\t\tEnter Name Of Product To Update: ");
	fgets(name,sizeof(name),stdin);
	name[strcspn(name,"\n")]='\0';
	if(fptr!=NULL){
		while(fread(&item,sizeof(item),1,fptr)){
			if(strcmp(item.name,name)==0){
			while(!valid){
			printf("\n\t\t\tEnter New ID:");
			valid=scanf("%d",&item.id);
			if(!valid){
				printf("\n\t\t\t\x1b[31mInvalid Input, Please Enter Correct ID\x1b[0m");
				while(getchar()!='\n');
			}	
			}	
            getchar();
			printf("\n\t\t\tEnter New Name:");
			fgets(item.name,sizeof(item.name),stdin);
			item.name[strcspn(item.name,"\n")]='\0';
			printf("\n\t\t\tEnter New Price:");
			scanf("%lf",&item.price);
			printf("\n\t\t\tEnter New Quantity:");
			scanf("%d",&item.quan);
			printf("\n\t\t\tEnter New Discounts:");
			scanf("%lf",&item.dis);
			fseek(fptr,-sizeof(Item),SEEK_CUR);
			fwrite(&item,sizeof(item),1,fptr);
			found=1;
			break;
			}
		}
		fclose(fptr);
		if(found!=1){
			printf("\n\t\t\t\x1b[31mProduct Not Found\x1b[0m");
		}
	}
	else{
		printf("\n\t\t\tFile Open Unsuccessful");
	}
}
void diszero(){
	int found=0;
	Item item;
	FILE*fptr;
	fptr=fopen("inven.txt","rb");
	if(fptr!=NULL){
		while(fread(&item,sizeof(item),1,fptr)){
			if(item.quan==0){
				printf("\n\t\t\tName: %s\t\t\tQuantity:%d",item.name,item.quan);
				found=1;
			}
		}
		fclose(fptr);
		if(found!=1){
			printf("\n\t\t\t\x1b[31mProduct With Zero Quantity Not Found\x1b[0m");
		}
	}
	else{
		printf("\n\t\t\tFile Open Unsuccessful");
	}
	
}
void dispro(){
	int found=0;
	Item item;
	FILE*fptr;
	fptr=fopen("inven.txt","rb");
	if(fptr!=NULL){
		while(fread(&item,sizeof(item),1,fptr)){
			if(item.dis>0){
				printf("\n\t\t\tName: %s",item.name);
				printf("\t\t\tDiscounts:%.2lf%%",item.dis);
				found=1;
			}
		}
		fclose(fptr);
		if(found!=1){
			printf("\n\t\t\t\x1b[31mDiscounted Products Not Found\x1b[0m");
		}
	}
	else{
		printf("\n\t\t\tFile Open Unsuccessful");
	}	
}
void sells1(){
	double income;
	int found=0;
	char cus[50];
	char name[50];
	double price;
	char content[1000];
	char content1[1000];
	sells sell;
	FILE*fptr;
	FILE*fptr1;
	fptr1=fopen("sells.txt","r");
	printf("\n-------------------------------------------------------------------------");
	printf("\n\t\t\t\t\t\t\t\x1b[33mTOTAL SELLS\x1b[0m\n");
	if(fptr1!=NULL){
	while(fgets(content,sizeof(content),fptr1)){
			if(sscanf(content, "%s %lf %s",&name,&price,&cus)==3){
			printf("\n\t\t\t\x1b[33mName: %s\t\t\tPrice: %.2lf\t\t\tCustomer: %s\x1b[0m\n",name,price,cus);
			found=1;	
			}
	}
	fclose(fptr1);
	fptr=fopen("total.txt","r");
	if(fptr!=NULL){
	if(found==1){
		while(fgets(content1,sizeof(content1),fptr)){
		income=atof(content1);
		printf("\n-------------------------------------------------------------------------");
	    printf("\n\t\t\t\t\t\t\x1b[33mTotal Income: %.2lf\x1b[0m",income);	
		}
		fclose(fptr);
	}
	else{
	printf("\n\t\t\t\t\t\t\x1b[33mNO SALES YET\x1b[0m");	
	}
	}
	}
else{
	printf("\n\t\t\t\x1b[31mFILE OPEN UNSUCCESSFUL\x1b[0m");
}
}
void customer(){
	char content[1000];
	char buyer[50];
	double finalprice;
	char pro1name[50];
	time_t currenttime;
	struct tm *current_tm;
	Item item;
	double dispriced;
	int cusinput;
	double price;
	char proname[50];
	while(1){
	printf("\n\t\t\t*******************\x1b[47m\x1b[30m WELCOME TO MAIN MENU \x1b[0m********************** \n\n");
	printf("\n\t\t\t\t\x1b[36m[1] Search Product ");
	printf("\n\t\t\t\t[2] Purchase Product");
	printf("\n\t\t\t\t[3] Generate Reciept");
	printf("\n\t\t\t\t[4] View Inventory");
	printf("\n\t\t\t\t[5] Exit Store\x1b[0m");
	printf("\n\t\t\t\t\x1b[32mEnter Your Choice:\x1b[0m ");
	scanf("%d",&cusinput);
	fflush(stdin);
	
    if(cusinput==1){
	 	printf("\n---------------------------------------------------------------------");
	 	int found=0;
	 	FILE*fptr;
	 	fptr=fopen("inven.txt","rb");
	 	printf("\n\t\t\tName Of Product:");
	 	fgets(proname,sizeof(proname),stdin);
	 	proname[strcspn(proname,"\n")]='\0';
	 	if(fptr!=NULL){
	 		while(fread(&item,sizeof(item),1,fptr)){
	 			if((strcmp(item.name,proname)==0)&&!(item.quan<1)){
	 				printf("\n\t\t\t\x1b[32mAvailable!!\x1b[0m");
	 				found=1;
				 }
				 else if((strcmp(item.name,proname)==0)&&(item.quan<1)){
				 printf("\n\t\t\t\x1b[31mOUT OF STOCK!!\x1b[0m");
				 found=1;	
				 }
			 }
			 fclose(fptr);
			 if(found!=1){
			 	printf("\n\t\t\t\x1b[31mProduct Not Found\x1b[0m");
			 }
		 }
		 else{
		 	printf("\n\t\t\tFile Open Unsuccessful");
		 }
	 }
	 else if(cusinput==2){
	 	char name[50];
	 	char pass[50];
	 	sells sell;
	 	double price;
	 	int quantity;
	 	printf("\n---------------------------------------------------------------------");
	 	int found=0;
	 	FILE*fptr1;
	 	FILE*fptr;
	 	FILE*fptr2;
	 	fptr1=fopen("sells.txt","a");
	 	fptr=fopen("inven.txt","rb+");
	 	printf("\n\t\t\tName Of Product(Purchase)");
	 	fgets(pro1name,sizeof(pro1name),stdin);
	 	pro1name[strcspn(pro1name,"\n")]='\0';
	 	if(fptr!=NULL){
	 		while(fread(&item,sizeof(item),1,fptr)){
	 			if(strcmp(item.name,pro1name)==0&&!(item.quan<1)){
	 				strcpy(sell.buyer,mybuyer);
	 				strcpy(sell.name,pro1name);
	 				sell.price=item.price;
	 				fprintf(fptr1, "%s %.2lf %s",sell.name,sell.price,sell.buyer);
	 				fprintf(fptr1,"\n");
	 				quantity=item.quan;
	 				quantity-=1;
	 				item.quan=quantity;
	 				fseek(fptr,-sizeof(item),SEEK_CUR);
	 				fwrite(&item,sizeof(item),1,fptr);
	 				printf("\n\t\t\t\x1b[32mProduct Purchased successfully\x1b[0m");
	 				time(&currenttime);
	 				current_tm=localtime(&currenttime);
	 				found=1;
	 				break;
				 }
				 else if(strcmp(item.name,pro1name)==0){
				 printf("\n\t\t\t\x1b[31mPRODUCT OUT OF STOCK!! {PURCHASE INCOMPLETE})\x1b[0m");
				 found=1;	
				 }
			 }
			 fclose(fptr1);
			 fclose(fptr);
			 if(found!=1){
			 	printf("\n\t\t\t\x1b[31mProduct Not Found\x1b[0m");
			 }
		 }
		 else{
		 	printf("\n\t\t\tFile Open Unsuccessful");
		 }
	 }
	 else if(cusinput==3){
	 	printf("\n---------------------------------------------------------------------");
	 	FILE*fptr;
	 	FILE*fptr1;
	 	fptr1=fopen("total.txt","r+");
	 	fptr=fopen("inven.txt","rb");
	 	if(fptr!=NULL){
	 	while(fread(&item,sizeof(item),1,fptr)){
	 		if(strcmp(item.name,pro1name)==0&&!(item.quan<1)){
	 			dispriced=(item.price*item.dis/100);
	 			finalprice=item.price-dispriced;
	 			time(&currenttime);
	 			current_tm=localtime(&currenttime);
	 			printf("\n\t\t\t\x1b[32mCustomer Name: %s\n\t\t\tProduct Name: %s\n\t\t\tDiscount: %.2lf\n\t\t\tProduct Price: %.2lf\n\t\t\tDiscounted Price: %.2lf\n\t\t\tDay:%02d-%02d-%04d\tTime=%02d:%02d:%02d\x1b[0m",mybuyer,pro1name,item.dis,
		        item.price,finalprice,current_tm->tm_mday, current_tm->tm_mon + 1, current_tm->tm_year + 1900,current_tm->tm_hour, current_tm->tm_min, current_tm->tm_sec);
		        break;
		 }
		 } 
	 }
	 else{
		 	printf("\n\t\t\tFile Open Unsuccessful");
		 }
		if(fptr1!=NULL){
		fscanf(fptr1,"%lf",&total);
		total=total+finalprice;
		fseek(fptr1,0,SEEK_SET);
		fprintf(fptr1,"%.2lf",total);
		}
		else{
			printf("\n\t\t\tFIle OPEN UNSUCCESSFUL\n");
		} 
		fclose(fptr1);
	}
	 else if(cusinput==4){
	 	viewinven();
	 }
	 else if(cusinput==5){
	 	return;
	 }
	 else if(cusinput>5 || cusinput<1){
	 	printf("\n\t\t\t\x1b[31mSELECT FROM OPTIONS!!\x1b[0m");
	 }	
	} 
}
