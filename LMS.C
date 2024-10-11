
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include<conio.h>
#include<windows.h>
// Structure for Book
struct books{
    int book_id;
    char bookName[50];
    char authorName[50];
    char bookpub[50];
    char pub_date[12]; 
    int quantity;
}b;
// Structure for Student 
struct student{
    int sid;
    char sName[50];
    char sClass[50];
    int sRoll;
    char gender[10];
    char sprogram[20];
    char semail[30];
    char address[20];
    char issueDate[12]; 
    char returnDate[12];
}s;
// Structure for Issue
struct issue {
    int book_id;
    int sid;
    char sName[50];
    char issueDate[12];
} i;

struct User { 
    char username[50]; 
    char password[50]; 
};

void addBook();
void addstudent();
void booklist();
void removebook();
void issuebook();
void issuebooklist();
void returnbook();
void menu();
void getPassword();

void getPassword(char* password) {
    char ch;
    int i = 0;
    while ((ch = getch()) != '\r') {  // '\r' is Enter key
        if (ch == '\b') {  // '\b' is Backspace key
            if (i > 0) {
                printf("\b \b");
                i--;
            }
        } else {
            password[i++] = ch;
            printf("*");
        }
    }
    password[i] = '\0';
    printf("\n");
}

int main() { 
    struct User users[2]; // You can increase the array size to store more users 
 
    // Initialize user data 
    strcpy(users[0].username, "user1"); 
    strcpy(users[0].password, "password1"); 
 
    strcpy(users[1].username, "user2"); 
    strcpy(users[1].password, "password2"); 
 
    char input_username[50]; 
    char input_password[50]; 
    int i; 
     printf("Enter Login Details \n"); 

    printf("Enter username: "); 
    scanf("%s", input_username); 
 
    printf("Enter password: "); 
    getPassword(input_password);
	 
    // Check if the input credentials match any user 
    for (i = 0; i < 2; i++) { 
        if (strcmp(input_username, users[i].username) == 0 && strcmp(input_password, users[i].password) == 0) { 
            printf("Login successful!\n"); 
            Sleep(2000);
            menu();
            break; 
        } 
    } 
 
    if (i == 2) { 
        printf("Login failed. Invalid username or password.\n"); 
        system("cls");
        main();
    } 
 
    return 0; 
} 

void menu(){
	system("cls");
    fflush(stdin);

    int num;
    printf("-----------------------------------------------\n");
    printf(">>> Library Management System <<< \n");
    printf("-----------------------------------------------\n\n");
    printf("> 1. Add Book \n");
    printf("> 2. Add Student \n");
    printf("> 3. List Book \n");
    printf("> 4. Remove Book \n");
    printf("> 5. Issue book \n");
    printf("> 6. Issue book List \n");
    printf("> 7. Return Book \n");
    printf("> 8. Close the Program... \n");

    printf("\nEnter Your Choice: ");
    scanf("%d",&num);

    fflush(stdin);

    switch(num)
    {
        case 1:
            addBook();
            break;
        case 2:
            addstudent();
            break;
        case 3:
            booklist();
            break;
        case 4:
            removebook();
            break;
        case 5:
            issuebook(0);
            break;
        case 6:
            issuebooklist();
            break;
        case 7:
            returnbook();
            break;
        case 8:
            exit(0);
            break;
        default:
            printf("Invalid Input! Choice 1 to 8");
            Sleep(2000);
            menu();
    }
}

void addBook(){
label1:
	system("cls");
	fflush(stdin);	
	FILE *fp = fopen("books.txt", "a+");
    if (fp == NULL) {
        printf("Unable to open the file.\n");
        return;
    }

    // Initialize the last book ID to 0
    int lastBookID = 0;

    // Read the last book ID from the file
    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.book_id > lastBookID) {
            lastBookID = b.book_id;
        }
    }

    fclose(fp);

    // Increment the last book ID for the new book
    b.book_id = lastBookID + 1;
    
	fp = fopen("books.txt","ab");
	
	if(fp != NULL){
		fflush(stdin);
		printf("----------------- Enter Book Details---------------------\n");
        printf("Book ID: %d\n", b.book_id);
		fflush(stdin);
		
        printf("Enter Book Name: ");
        gets(b.bookName);
		fflush(stdin);
		
        printf("Enter Book Author Name: ");
        gets(b.authorName);
		fflush(stdin);
		
        printf("Enter Book Pulication: ");
		gets(b.bookpub);    
		  
        printf("Enter Book Pulication Year: ");
		gets(b.pub_date);
		
        printf("Enter Book Quantity: ");
        scanf("%d",&b.quantity);
        
    	fwrite(&b, sizeof(b), 1, fp);
        
        printf("\n >>> Book record added Successfully <<<\n");
	}
	else{
		
		printf("Unable to Open Located the file.");
	}
	fclose(fp);
	fflush(stdin);
	
	char input;
	printf("\n Do You Wanna Enter More Book Details[y/N]:");
	scanf("%c",&input);
	if(input == 'y'|| input == 'Y'){
		goto label1; 
	}
	else if( input=='n' || input=='N'){
		printf("\n Redirecting to Main Menu.");
		Sleep(2000);
		menu();
	}
	else{
		printf("\nInvaild input. Redirecting to Book Panel.");
        Sleep(2000);
        menu();
	}
	
}

void addstudent(){
	label2:
	system("cls");
	fflush(stdin);
	
	FILE *pF = fopen("student.txt","ab+");
	
	if(pF != NULL){
		fflush(stdin);
		printf("----------------- Enter Student Details---------------------\n");
		printf("Enter Student ID: ");
		scanf("%d",&s.sid);	
		fflush(stdin);
		
        printf("Enter Student Name: ");
        gets(s.sName);
		fflush(stdin);
		
        printf("Enter Student Class: ");
        gets(s.sClass);
		fflush(stdin);
		
        printf("Enter Student Program: ");
		gets(s.sprogram);    
		  
        printf("Enter Student Roll No: ");
		scanf("%d",&s.sRoll);
		
		printf("Enter Student Email: ");
		scanf("%d",&s.semail);
		fflush(stdin);
		
		printf("Enter Student Address: ");
		scanf("%s", s.address);
		fflush(stdin);
        
    	fwrite(&s, sizeof(s), 1, pF);

        
        printf("\n >>> Student record added Successfully <<<\n");
	}
	else{
		printf("Unable to Open Located the file.");
	}
	fclose(pF);
	fflush(stdin);
	
	char input;
	printf("\n Do You Wanna Enter More Studnet Details[y/N]:");
	scanf("%c",&input);
	if(input == 'y'|| input == 'Y'){
		goto label2;
	}
	else if( input=='n' || input=='N'){
		printf("\n Redirecting to Main Menu.");
		Sleep(2000);
		menu();
	}
	else{
		printf("\nInvaild input. Redirecting to Book Panel.");
        Sleep(2000);
        menu();
	}
	
}

void booklist(){
	system("cls");
    printf("<== Available Books ==>\n\n");
	printf("%-10s | %-20s | %-20s | %-20s | %-20s | %s\n", "Book ID", "Book Name", "Author", "Publication", "Publication Year", "Quantity");
    printf("--------------------------------------------------------------------------------------------------------\n");
    FILE *fp = fopen("books.txt", "rb");
    while (fread(&b, sizeof(b), 1, fp) == 1){
        printf("%-10d | %-20s | %-20s | %-20s | %-20s | %d\n", b.book_id, b.bookName, b.authorName,  b.bookpub, b.pub_date, b.quantity);
    }
    printf("\n\n Press any key to get back to User Panel.\n");
    Sleep(2000);
    getch();
    menu();
}
   	
void removebook(){
system("cls");
    fflush(stdin);
   FILE *fp, *newfp;
	int roll;
	
	fp = fopen("books.txt","r");
	if(fp == NULL){
		printf("\nfile is not exits");
		exit(0);
	}
	
	newfp = fopen("temp.txt","w+");
	if(newfp == NULL){
		printf("\nfile could not be open");
		exit(0);
	}
	printf("----------------- Remove Book ---------------------\n");
	printf("\n\n Enter the book name you want to delete: ");
	scanf("%d", &roll);
	while(fread(&b, sizeof(b), 1, fp)){
		if(b.book_id != roll){
			fwrite(&b, sizeof(b), 1, newfp);
		}
	}
	fclose(fp);
	fclose(newfp);
	remove("books.txt");
	rename("temp.txt","books.txt");
	printf("\n >>> Book Remove Successfully <<<\n");
    printf("Redirecting to Main Menu...");
    Sleep(2000);
    menu();
}

void issuebook(){
    system("cls");
    fflush(stdin);

    int book_id, student_id;
    printf("<== Issue Books ==>\n\n");

    printf("Enter Book ID to issue: ");
    scanf("%d", &book_id);

    // Check if the book is available
    FILE *fp = fopen("books.txt", "rb+");
    int book_found = 0;

    while (fread(&b, sizeof(b), 1, fp) == 1) {
        if (b.book_id == book_id) {
            book_found = 1;
            if (b.quantity > 0) {
                b.quantity -= 1;
                fseek(fp, sizeof(b), SEEK_CUR);
                fwrite(&b, sizeof(b), 1, fp);
                break;
            } else {
                printf("Book is not available.\n");
                fclose(fp);
                printf("Redirecting to Main Menu...\n");
                Sleep(2000);
                menu();
                return;
            }
        }
    }

    fclose(fp);

    if (!book_found) {
        printf("No book found with this ID.\n");
        printf("Redirecting to Main Menu...\n");
        Sleep(2000);
        menu();
        return;
    }

    printf("Enter Student ID: ");
    scanf("%d", &student_id);

    // Check if the student exists
    FILE *student_fp = fopen("student.txt", "rb");
    int student_found = 0;

    while (fread(&s, sizeof(s), 1, student_fp) == 1) {
        if (s.sid == student_id) {
            student_found = 1;
            break;
        }
    }

    fclose(student_fp);

    if (!student_found) {
        printf("No student found with this ID.\n");
        printf("Redirecting to Main Menu...\n");
        Sleep(2000);
        menu();
        return;
    }

    // Get current date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(i.issueDate, "%02d-%02d-%d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    // Record issue details
    i.book_id = book_id;
    i.sid = student_id;
    strcpy(i.sName, s.sName);  // Use the student's name from the student file

    FILE *issue_fp = fopen("issue.txt", "ab");
    if (issue_fp != NULL) {
        fwrite(&i, sizeof(i), 1, issue_fp);
        fclose(issue_fp);
        printf("Book Issued Successfully\n\n");
    } else {
        printf("Unable to open issue file.\n");
    }

    printf("Redirecting to Main Menu...\n");
    Sleep(2000);
    menu();
}

void issuebooklist(){
    system("cls");
    fflush(stdin);

    printf("<== Issued Book List ==>\n\n");
    printf("%-20s | %-10s | %-20s | %-20s | %-20s | %-12s\n", "Student Name", "Book ID", "Book Name", "Author", "Publication", "Issue Date");
    printf("------------------------------------------------------------------------------------------------------------------\n");

    FILE *issue_fp = fopen("issue.txt", "rb");
    FILE *book_fp = fopen("books.txt", "rb");

    if (issue_fp == NULL || book_fp == NULL) {
        printf("Unable to open file.\n");
        printf("Redirecting to Main Menu...\n");
        Sleep(2000);
        menu();
        return;
    }

    while (fread(&i, sizeof(i), 1, issue_fp) == 1) {
        // Reset file pointer to the beginning of books.txt
        fseek(book_fp, 0, SEEK_SET);

        while (fread(&b, sizeof(b), 1, book_fp) == 1) {
            if (b.book_id == i.book_id) {
                printf("%-20s | %-10d | %-20s | %-20s | %-20s | %-12s\n",i.sName, b.book_id, b.bookName, b.authorName, b.bookpub, i.issueDate);
                printf("------------------------------------------------------------------------------------------------------------------\n");
                break;
            }
        }
    }

    fclose(issue_fp);
    fclose(book_fp);

    printf("\nPress any key to return to the main menu...");
    getch();
    menu();
}

void returnbook(){
    system("cls");
    fflush(stdin);

    int flag = 0;
    int compare_name, compare_id;
    int days;
    double fine = 0;
    char find_name[50];
    int find_book_id;

    printf("Enter the name of the student returning the book: ");
    gets(find_name);

    printf("Enter the Book ID being returned: ");
    scanf("%d", &find_book_id);

    FILE *issue_fp = fopen("issue.txt", "rb");
    FILE *temp_fp = fopen("temporary.txt", "wb");

    if (issue_fp == NULL || temp_fp == NULL) {
        printf("Unable to open file.\n");
        printf("Redirecting to Main Menu...\n");
        Sleep(2000);
        menu();
        return;
    }

    while (fread(&i, sizeof(i), 1, issue_fp) == 1) {
        compare_name = strcmp(find_name, i.sName);
        compare_id = (find_book_id == i.book_id);

        if (compare_name == 0 && compare_id) {
            printf("Enter the return date (dd-mm-yyyy): ");
            scanf("%s", s.returnDate);

            // Calculate the number of days the book was held
            int issue_day, issue_month, issue_year;
            int return_day, return_month, return_year;

            sscanf(i.issueDate, "%d-%d-%d", &issue_day, &issue_month, &issue_year);
            sscanf(s.returnDate, "%d-%d-%d", &return_day, &return_month, &return_year);

            struct tm issue_tm = {0, 0, 0, issue_day, issue_month - 1, issue_year - 1900};
            struct tm return_tm = {0, 0, 0, return_day, return_month - 1, return_year - 1900};

            time_t issue_time = mktime(&issue_tm);
            time_t return_time = mktime(&return_tm);

            double difference = difftime(return_time, issue_time) / (60 * 60 * 24);
            days = (int)difference;

            // Assuming a fine of Rs 10 per day after a due period of 14 days
            if (days > 14) {
                fine = (days - 14) * 10.0;
            }

            printf("The book was held for %d days.\n", days);
            if (fine > 0) {
                printf("The fine is Rs%.2f.\n", fine);
            } else {
                printf("No fine.\n");
            }

            // Increase the quantity of the book in books.txt
            FILE *book_fp = fopen("books.txt", "rb+");
            if (book_fp != NULL) {
                while (fread(&b, sizeof(b), 1, book_fp) == 1) {
                    if (b.book_id == find_book_id) {
                        b.quantity += 1;
                        fseek(book_fp, sizeof(b), SEEK_CUR);
                        fwrite(&b, sizeof(b), 1, book_fp);
                        break;
                    }
                }
                fclose(book_fp);
            }

            printf(">>> Book Successfully Return <<<\n");
            flag = 1;
        } else {
            fwrite(&i, sizeof(i), 1, temp_fp);
        }
    }

    fclose(issue_fp);
    fclose(temp_fp);

    if (flag == 0) {
        printf("Record Not Found.\n");
    } else {
        remove("issue.txt");
        rename("temporary.txt", "issue.txt");
    }

    printf("Redirecting to Main Menu...\n");
    getch();
    Sleep(2000);
    menu();
}
