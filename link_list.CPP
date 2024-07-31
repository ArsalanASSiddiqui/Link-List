#include <iostream>
using namespace std;
class node
{
public:
  int data;
  node *next;
    node (int val)
  {
	data = val;
	next = NULL;
  }
};
class linkedList
{
public:
  node* head=NULL;
};
void pushback(node* &header,int val){
    std::cout <<"in pushback top 1 head" << header << std::endl;
    node* n1 = new node(val);
    std::cout <<"new node adress "<< n1 << std::endl;
    if(header==NULL){
        header=n1;
        cout <<"Replace new n1 address to header"<< header << std::endl;
        cout<<"again print n1 addess to check"<< n1  << std::endl;
        return;
 
    }
     cout<<"new node"  << std::endl;
     node* tem = header;
    while(tem->next!=NULL){
        tem=tem->next;
    }
    tem->next=n1;
    cout<< "now Replace last node null to new address and again new node is null "<< n1  << std::endl;
 
}
void showdata(node* header){
    std::cout <<"in show function head"<< header << std::endl;
    while(header!=NULL){
        std::cout << header->data << std::endl;
        header=header->next;
    }
    cout<<endl;
}
void pushfront(node* &header,int val){
    node* n = new node(val);
    std::cout <<"n node address"<< n->next << std::endl;
  std::cout <<"Header address"<< header << std::endl;
  n->next=header;
    std::cout <<"check n (n is new node) personal address"<< n<< std::endl;
  header=n;
 
}
bool search(node* header,int val){
    node* se = header;
    std::cout << "ch"<<se << std::endl;
  while(se!=NULL){
      if(se->data==val){
          std::cout <<"number "<< se->data  <<" is found in list" << std::endl;
          return true;
      }
      se=se->next;
  }
  std::cout << "number "<< val <<" Not found in list" << std::endl;
  return false;
 
}
void insertinto(node* &header,int val ,int insert){
    node* newNodeinsertinto = new node(insert);
    node* sear = header;
    int count=1;
    while(sear!=NULL){
        if(count==val){
            std::cout << "befor chage address of search node"<<sear->next << std::endl;
            std::cout << "befor chage address of new node"<<newNodeinsertinto << std::endl;
            newNodeinsertinto->next= sear->next;
            sear->next=newNodeinsertinto;
            newNodeinsertinto=sear->next;
            std::cout << "After chage address of search node"<<sear->next << std::endl;
            std::cout << "After chage address of new node"<<newNodeinsertinto->next << std::endl;
            return;
        }
        sear=sear->next;
        count++;
    }
    std::cout <<val<< "List length is less than number" << std::endl;
    return;
}
void deletefunction(node* &header,int val){
    int count = 1;
    int precount = 1;
    std::cout <<"position is"<< count << std::endl;
    node* n=header;
    node* pren=header;
    while(n!=NULL){
        if(count==val){
             std::cout << "Value " << val << " found at position " << count << std::endl;
             std::cout << "position" <<count<<"Address is"<<n << std::endl;
             while(pren!=NULL){
                 if(precount==count-1){
                     std::cout <<"check Count"<< pren->next << pren->data  << std::endl;
                     std::cout << "current value previus reference "<< n->next <<n->data << std::endl;
                     pren->next=n->next;
                 }
                 pren=pren->next;
                 precount++;
             }
        }
        n=n->next;
        count++;
 
    }
}
int main ()
{
  linkedList listhead;
  std::cout <<"in Main top " <<listhead.head << std::endl;
  pushback(listhead.head,6);
  pushback(listhead.head,8);
  pushback(listhead.head,9);
  showdata(listhead.head);
  pushfront(listhead.head,11);
  pushfront(listhead.head,19);
 
  showdata(listhead.head);
  search(listhead.head,6);
  insertinto(listhead.head,24,27);
  showdata(listhead.head);
  deletefunction(listhead.head,4);
  showdata(listhead.head);
 
  
  std::cout << "Hello World";
  // std::cout << listhead.head << std::endl; 
  return 0;
}