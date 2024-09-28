#include <iostream>

using namespace std;

class Node{
   public:
      string songName;
      Node* next;
      Node* prev;
   
   //constructor
   Node(string song){
      this->songName = song;
      this->next = nullptr;
      this->prev = nullptr;
   }
};


class MusicPlayList{
   private:
      Node* current;
      Node* head;
      Node* tail;
   
   public:
      //constructor
      MusicPlayList(){
         this->current = nullptr;
         this->head = nullptr;
      }

      string getCurrentSong(){
         return this->current->songName;
      }

      //Insert a song
      void add(string song){
         Node* newNode = new Node(song);

         //if list is empty
         if(this->head == nullptr){
            this->head = this->tail = newNode;
            return;
         }

         this->tail->next = newNode;
         newNode->prev = this->tail;
         this->tail = newNode;
      }

      //show playlist
      void show(){
         Node* current = head;
         while(current != nullptr){
            cout << current->songName << " -> ";
            current = current->next;
         }

         cout << "\n";
      }

      //start playing playlist. plays the head
      void play(){
         this->current = head;
         cout << "Playing : " << this->current->songName << "\n";
      }

      void forward(){
         //If reached end move to the top;
         if(this->current->next == nullptr){
            this->play();
            return;
         }

         this->current = this->current->next;
         cout << "Playing : " << this->current->songName << endl;
      }

      void backward(){
         //If reached end move to the tail;
         if(this->current->prev == nullptr){
            this->current = this->tail;
            cout << "Playing : " << this->current->songName << endl;
            return;
         }
         this->current = this->current->prev;
         cout << "Playing : " << this->current->songName << endl;
      }
};


int main(){
   
   MusicPlayList myPlaylist;

   myPlaylist.add("505 by Artic Monkey");
   myPlaylist.add("Jhol");
   myPlaylist.add("Die for you");
   myPlaylist.add("Tere Liye");
   myPlaylist.add("Blinding Lights");
   myPlaylist.add("Old Money");
   
   cout << "Displaying playlist : \n";
   myPlaylist.show();
   cout << "\n";

   int userChoice = 999;
   cout << "----------Playing the playlist----------\n";
   cout << "Press 1 to forward, 0 to go back, -1 to stop playing\n";
   cout << endl;

   myPlaylist.play();

   while(userChoice != -1){
      cout << "next/back/stop : ";
      cin >> userChoice;

      if(userChoice == 1){
         myPlaylist.forward();
      }else if(userChoice == 0){
         myPlaylist.backward();
      }else if(userChoice == -1){
         break;
      }else{
         cout << "Invalid Choice\n";
         cout << "Playing : " << myPlaylist.getCurrentSong() << endl;
      }

      cout << endl;
   }

   cout << "Exited the playlist.";
   return 0;
}