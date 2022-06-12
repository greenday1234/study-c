package library;

public class Book {   
      private String title;
      private String author;
      private String ISBN;
      private String rent;
      private String borrowDate;
      public Book(String title,String author,String ISBN,String rent,String borrowDate) {
         this.title=title;
         this.author=author;
         this.ISBN=ISBN;
         this.rent=rent;
         this.setBorrowDate(borrowDate);
      // TODO Auto-generated constructor stub
   }
      public Book(String title,String author,String ISBN) {
          this.title=title;
          this.author=author;
          this.ISBN=ISBN;
          this.rent="대여가능";
          this.setBorrowDate(" ");
       // TODO Auto-generated constructor stub
    }
   public String getTitle() {
      return title;
   }
   public void setTitle(String title) {
      this.title = title;
   }
   
   public String getAuthor() {
      return author;
   }
   public void setAuthor(String author) {
      this.author = author;
   }
   
   public String getISBN() {
      return ISBN;
   }
   public void setISBN(String iSBN) {
      ISBN = iSBN;
   }
   
   public String getRent() {
      return rent;
   }
   public void setRent(String rent) {
      this.rent = rent;
   }  
   
   public String toString() {
	   return title+"/"+author+"/"+ISBN+"/"+rent+"/"+borrowDate+"/";
   }
public String getBorrowDate() {
	return borrowDate;
}
public void setBorrowDate(String borrowDate) {
	this.borrowDate = borrowDate;
}
   
}