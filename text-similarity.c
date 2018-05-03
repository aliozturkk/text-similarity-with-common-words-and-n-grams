#include<stdlib.h>
#include<stdio.h>
#include<string.h>

typedef struct node {
	
	char word[42];
	struct node *nextNode;
	
}node;

void removePunctuation(char word[42]);
void readFile(node *list,char fileName[42]); 
void termFrequency(node *firstLinkedList,node *secondLinkedList,node *newLinkedList);
void addNode(node *list,char temp[42]);
void print(node *printList);
void addItemTermFrequencyList(char temp[42],node *newLinkedList);
node *sortWordToAlphabet( node *linkedList );
void counterWord(node *list);

void mergeWord( node *linkedList,node *linkedList2);


int main(){
	
	system("color B"); // for color
	
	                 /* question a  */
	            
    node *firstTextRoot=(node *) malloc (sizeof(node));   
    node *secondTextRoot=(node *) malloc (sizeof(node));
    node *thirdTextRoot=(node *) malloc (sizeof(node));
    firstTextRoot->nextNode=NULL;
    secondTextRoot->nextNode=NULL;
    thirdTextRoot->nextNode=NULL;
    
    
    readFile(firstTextRoot,"file1.txt");
    readFile(secondTextRoot,"file2.txt");
    termFrequency(firstTextRoot,secondTextRoot,thirdTextRoot);
    thirdTextRoot=sortWordToAlphabet( thirdTextRoot );
    printf("\nthe number of common words: ");
    counterWord(thirdTextRoot);
    printf("\nthe common words are: \n");
    print(thirdTextRoot);
    
               
                      /*  question b */
    printf("\n--------------------------------------------------------------------------------");
    node *fourthTextRoot=(node *) malloc (sizeof(node));
    node *fifthTextRoot=(node *) malloc (sizeof(node));   
	node *sixthTextRoot=(node *) malloc (sizeof(node));  
	fourthTextRoot->nextNode=NULL;
	fifthTextRoot->nextNode=NULL;
	sixthTextRoot->nextNode=NULL;
	
	mergeWord( firstTextRoot,fourthTextRoot );
	mergeWord( secondTextRoot,fifthTextRoot );
	termFrequency(fourthTextRoot,fifthTextRoot,sixthTextRoot);
	sixthTextRoot=sortWordToAlphabet( sixthTextRoot );
	printf("\nthe number of common words: ");
    counterWord(sixthTextRoot);
	printf("\nthe common words are: \n");
	print(sixthTextRoot);

	
	
}


void print(node *printList){

	while(printList!=NULL){
		
		printf("%s \n",printList->word);
	    printList=printList->nextNode;
	   
	}
	
	
}
void counterWord(node *list){
	int count=0;
	while(list!=NULL){
		
	
	    list=list->nextNode;
	   count++;
	}
    	printf("%d",count);
}

void readFile(node *list,char fileName[42]){
	FILE *file;
	file=fopen(fileName,"r");//open file for read
    node *temp;
    char tempWord[42];
	while(fscanf(file,"%s",tempWord)!=EOF){     // write information on linked list from file //
	
	
	
        tempWord[0]=tolower(tempWord[0]);
        removePunctuation(&tempWord);
        strcpy(list->word,tempWord);        
		list->nextNode=(node *) malloc (sizeof(node));
		list->nextNode->nextNode=NULL;
	    temp=list;
		list=list->nextNode;
      
	
	}
	temp->nextNode=NULL;
	free(list);
	
}

void removePunctuation(char word[42]){
		
	          int i=0;
	          while(word[i]!=NULL){  // this while for remove punctuations
	          	  if(word[i]<=47 && word[i]>=33)
	          	  word[i]= NULL;
				  i++;
			  }	

}



void termFrequency(node *firstLinkedList,node *secondLinkedList,node *newLinkedList){
   node *iter1=firstLinkedList;
   node *iter2=secondLinkedList;
   
	while(iter1!=NULL){
		
	while(iter2!=NULL){
		
		if(strcmp(iter1->word,iter2->word)==0){
			
			addItemTermFrequencyList(iter1->word,newLinkedList);
		}
		
		iter2=iter2->nextNode;
	}	
				
	iter2=secondLinkedList;	
	iter1=iter1->nextNode;	
	}

		
}

void addItemTermFrequencyList(char temp[42],node *newLinkedList){

node *iter;
node *iter2;
while(newLinkedList!=NULL){
	
if(strcmp(newLinkedList->word,temp)==0){
	
	return 0;
}	
iter=newLinkedList;
newLinkedList=newLinkedList->nextNode;
}

strcpy(iter->word,temp);
iter->nextNode=(node *) malloc (sizeof(node));
iter->nextNode->nextNode=NULL;


}


node *sortWordToAlphabet( node *linkedList )
{
   node *p, *q, *top;
   node *l1;
   node *l2;
    int changed = 1;

   top = (node *)malloc(sizeof(node));

    top->nextNode = linkedList;
    if( linkedList != NULL && linkedList->nextNode != NULL ) {

        while( changed ) {
            changed = 0;
            q = top;
            p = top->nextNode ;
            while( p->nextNode  != NULL ) {
               
                if( strcmp(p->word , p->nextNode ->word)>0 ) {
                    l1=p;
					l2=p->nextNode ;
					l1->nextNode  = l2->nextNode ;
                    l2->nextNode  = l1;
                    q->nextNode  = l2;
                    changed = 1;
                }
                q = p;
                if( p->nextNode != NULL )
                    p = p->nextNode ;
            }
        }
    }
    
    
    p = top->nextNode ;
    free( top );
    
    
    node *temp=p;
    p=p->nextNode;
    free(temp);
    
    
	return p;
    
    
}

void mergeWord( node *linkedList,node *linkedList2){
	
	node *iter=linkedList;
	node *iter2=linkedList->nextNode;
	node *iter3;
	
	
	while(iter2!=NULL){
		char temp[84]="";
	
		int i=0;
		while(iter->word[i]!=NULL){
			
			temp[i]=iter->word[i];
			i++;
		}
		temp[i]=32;
		i++;
		
		int j=0;
		
		while(	iter2->word[j]!=NULL){
			
				temp[i]=iter2->word[j];
				
				i++;
				j++;
		}
				
		strcpy(linkedList2->word,temp);
		iter=iter->nextNode;
		iter2=iter2->nextNode;
		
		iter3=linkedList2;
		linkedList2->nextNode=(node *)malloc(sizeof(node));
		linkedList2=linkedList2->nextNode;
		linkedList2->nextNode=NULL;
	}
		
}



