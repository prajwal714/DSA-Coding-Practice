#include<bits/stdc++.h>
using namespace std;

const int  MAX_BOOKS_ISSUED_TO_USER=5;
const int MAX_LENDING_DAYS=10;

enum BookFormat{
    HARDCOVER,
    PAPERBACK
};

enum BookStatus{
    AVAILABLE,
    RESERVED,
    LOANED,
    LOST
};

enum ReservationStatus{
    WAITING,
    PENDING,
    CANCELED,
    NONE 
};

enum AccountStatus{
    ACTIVE,
    CLOSED,
    CANCELED,
    BLACKLISTED,
    NONE
};

class Address{
    private:
        string streetAddress, city, state, zipcode, country;

};

class Person{
    private:
        string name, email, phone;
        Address address;
};

//==================================================================================================

class Account{
    private:
        string id, password;
        AccountStatus status;
        Person person;
};

class Member: Account {
    private:
        Date dateOfMembership;
        int totalBooksCheckout;

        void incrementTotalBooksCheckout();

    public:
        int getTotalBooksCheckedout();
        bool reserveBookItem(BookItem bookItem);

        bool checkoutBookItem(BookItem bookItem)
        {
            if (this->getTotalBooksCheckedout()>=MAX_BOOKS_ISSUED_TO_USER) {
                ShowError("The User has already checked out max number of books");
                return false;
            }

            BookReservation bookReservation=BookReservation.fetchReservationDetails(bookItem.getBarcode());

            if(bookReservation!=NULL && bookReservation.getMemberId()!=this->getId())
            {
                ShowError("This Book is Reserved by another user");
                return false;
            }
            else if(bookReservation!=NULL){
                bookReservation.updateStatus(ReservationStatus.COMPLETED);
            }

            if (!bookItem.checkout(this->getId()))
            {
                return false;
            }

            this->incrementTotalBooksCheckout();
            return true;

        }

        void returnBookItem(BookItem bookItem){
            this->checkForFine(BookItem.getBarcode());
            BookReservation bookReservation=BookReservation.fetchReservationDetails(bookItem.getBarcode());

            if(bookReservation!=NULL){
                bookItem.updateBookItemStatus(BookStatus.RESERVED);
                bookReservation.sendBookAvailableNotification();


            }

            bookItem.updateBookItemStatus(BookStatus.AVAILABLE);
        }

        bool renewBookItem(BookItem bookItem){
            this.checkForFine(bookItem.getBarcode());

            BookReservation bookReservation=BookReservation.fetchReservationDetails(bookItem.getBarcode());

            if(bookReservation!=NULL && bookReservation.getMemberId()!=this->getMemberId()){
                ShowError("This Book is reserved by another member");
                member.decrementTotalBooksCheckedout();
                bookItem.updateBookItemState(BookStatus.RESERVED);
                bookReservation.sendBookAvailableNotification();
                return false;
            } else if(bookREservation!=NULL) {
                bookReservation.updateStatus(ReservationStatus.COMPLETED);
            }

            
        }



};


class Librarian: Account {
    public:
        void addBookItem(BookItem bookItem);
        void blockMember(Member member);
        void unBlockMember(Member member);

};




