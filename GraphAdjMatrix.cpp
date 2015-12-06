//#include<stdio.h>
//#include<stdlib.h>
//#include<limits.h>
//#define NULL_VALUE -999999
//#define INFINITY 999999


//class Queue
//{
//    int queueInitSize ;
//    int queueMaxSize;
//    int * data;
//    int length;
//    int front;
//    int rear;
//public:
//    Queue();
//    ~Queue();
//    void enqueue(int item); //insert item in the queue
//    int dequeue(); //returns the item according to FIFO
//    bool empty(); //return true if Queue is empty
//};

//Queue::Queue()
//{
//    queueInitSize = 2 ;
//    queueMaxSize = queueInitSize;
//    data = new int[queueMaxSize] ; //allocate initial memory
//    length = 0 ;
//    front = 0;
//    rear = 0;
//}


//void Queue::enqueue(int item)
//{
//    if (length == queueMaxSize)
//    {
//        int * tempData ;
//        //allocate new memory space for tempList
//        queueMaxSize = 2 * queueMaxSize ;
//        tempData = new int[queueMaxSize] ;
//        int i, j;
//        j = 0;
//        for( i = rear; i < length ; i++ )
//        {
//            tempData[j++] = data[i] ; //copy items from rear
//        }
//        for( i = 0; i < rear ; i++ )
//        {
//            tempData[j++] = data[i] ; //copy items before rear
//        }
//        rear = 0 ;
//        front = length ;
//        delete[] data ; //free the memory allocated before
//        data = tempData ; //make list to point to new memory
//    }

//    data[front] = item ; //store new item
//    front = (front + 1) % queueMaxSize ;
//    length++ ;
//}


//bool Queue::empty()
//{
//    if(length == 0) return true ;
//    else return false ;
//}


//int Queue::dequeue()
//{
//    if(length == 0) return NULL_VALUE ;
//    int item = data[rear] ;
//    rear = (rear + 1) % queueMaxSize ;
//    length-- ;
//    return item ;
//}


//Queue::~Queue()
//{
//    if(data) delete[] data; //deallocate memory
//    data = 0; //set to NULL
//}

////****************Queue class ends here************************


////******************Graph class starts here**************************
//class Graph
//{
//    int nVertices, nEdges ;
//    bool directed ;
//    int ** matrix ; //adjacency matrix to store the graph
//    int *color,*distance,*parent;

//    //define other variables required for bfs such as color, parent, and dist
//    //you must use pointers and dynamic allocation

//public:
//    Graph(bool dir = false);
//    ~Graph();
//    void setnVertices(int n);
//    void addEdge(int u, int v);
//    void removeEdge(int u, int v);
//    bool isEdge(int u, int v);
//    int getDegree(int u);
//    void printAdjVertices(int u);
//    bool hasCommonAdjacent(int u, int v);
//    int getDist(int u, int v);
//    void printGraph();
//    void bfs(int source); //will run bfs in the graph
//};


//Graph::Graph(bool dir)
//{
//    nVertices = 0 ;
//    nEdges = 0 ;
//    matrix = 0 ;
//    directed = dir ; //set direction of the graph
//    color=0;//define other variables to be initialized
//    distance=0;
//    parent=0;
//}

//void Graph::setnVertices(int n)
//{
//    this->nVertices = n ;

//    //allocate space for the matrix
//    matrix = new int*[nVertices];
//    for(int i=0;i<nVertices;i++)
//    {
//        matrix[i] = new int[nVertices];
//        for(int j=0;j<nVertices;j++)
//            matrix[i][j] = 0; //initialize the matrix cells to 0
//    }
//    color=new int[nVertices];
//    distance=new int[nVertices];
//    parent=new int[nVertices];

//}

//void Graph::addEdge(int u, int v)
//{
//    //write your code here
//    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;
//    matrix[u][v] = 1;
//    if(!directed) matrix[v][u] = 1;
//    nEdges++;

//}

//void Graph::removeEdge(int u, int v)
//{
//    //write this function
//    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return;

//    if(!directed)
//    {
//        matrix[v][u] = 0;
//        matrix[u][v]=0;
//        nEdges--;
//    }
//    else
//    {
//        matrix[u][v]=0;
//        nEdges--;
//    }

//}

//bool Graph::isEdge(int u, int v)
//{
//    //returns true if (u,v) is an edge, otherwise should return false
//    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return false;
//    if(matrix[u][v]==1)return true;
//    if(!directed && matrix[v][u]==1)return true;
//    return false;
//}

//int Graph::getDegree(int u)
//{
//    //returns the degree of vertex u
//    if(u<0 || u>=nVertices ) return -1;
//    int cnt=0;
//    for(int i=0;i<nVertices;i++)
//    {
//        if(matrix[u][i]==1)cnt++;
//    }
//    return cnt;
//}

//void Graph::printAdjVertices(int u)
//{
//    //prints all adjacent vertices of a vertex u
//    if(u<0 || u>=nVertices ) return;
//    for(int i=0;i<nVertices;i++)
//    {
//        if(matrix[u][i]==1)printf("%d ",i);
//    }
//    printf("\n");
//}

//bool Graph::hasCommonAdjacent(int u, int v)
//{
//    //returns true if vertices u and v have common adjacent vertices
//    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return false;
//    for(int i=0;i<nVertices;i++)
//    {
//        if(matrix[u][i]==1&&matrix[v][i]==1)return true;
//    }
//    return false;
//}

//void Graph::bfs(int source)
//{
//    //write this function
//    for(int i=0;i<nVertices;i++)
//    {
//        color[i]=1;
//        distance[i]=INFINITY;
//        parent[i]=-1;
//    }
//    color[source]=2;
//    distance[source]=0;
//    parent[source]=0;
//    Queue Q;
//    Q.enqueue (source);
//    while(!Q.empty ())
//    {
//        int u=Q.dequeue ();
//        for(int i=0;i<nVertices;i++)
//        {
//            if(matrix[u][i]==1 && color[i]==1)
//            {
//                color[i]=2;
//                distance[i]=distance[u]+1;
//                parent[i]=u;
//                Q.enqueue (i);
//            }
//        }
//        color[u]=3;
//    }

//}

//int Graph::getDist(int u, int v)
//{
//    //returns the shortest path distance from u to v
//    //must call bfs using u as the source vertex, then use distance array to find the distance
//    if(u<0 || u>=nVertices || v<0 || v>=nVertices) return NULL_VALUE;
//    bfs(u);
//    return distance[v];

//}


//void Graph::printGraph()
//{
//    printf("\nNumber of vertices: %d, Number of edges: %d\n", nVertices, nEdges);
//    for(int i=0;i<nVertices;i++)
//    {
//        printf("%d:", i);
//        for(int j=0; j<nVertices;j++)
//        {
//            if(matrix[i][j]==1)
//                printf(" %d", j);
//        }
//        printf("\n");
//    }
//}

//Graph::~Graph()
//{
//    //write your destructor here
//    if(matrix)
//    {
//        for(int i=0;i<nVertices;i++)
//            delete [] matrix[i];
//        delete [] color;
//        delete [] distance;
//        delete [] parent;
//        matrix=0;
//        color=0;
//        parent=0;
//        distance=0;
//    }
//}


////**********************Graph class ends here******************************


////******main function to test your code*************************
//int main(void)
//{
//    int n;
//    Graph g;
//    printf("Enter number of vertices: ");
//    scanf("%d", &n);
//    g.setnVertices(n);

//    while(1)
//    {
//        printf("1. Add edge. 2. Remove edge. 3. Is edge? 4. Get Degree\n");
//        printf("5. Print Adjacent Vertices. 6. Print Graph  7. Has common adjacent? \n");
//        printf("8. Get distance.\n");

//        int ch;
//        scanf("%d",&ch);
//        if(ch==1)
//        {
//            int u, v;
//            scanf("%d%d", &u, &v);
//            g.addEdge(u, v);
//        }
//        else if(ch==2)
//        {
//            int u,v;
//            printf("Vertices?\n");
//            scanf ("%d%d",&u,&v);
//            g.removeEdge (u,v);
//        }
//        else if(ch==3)
//        {
//            int u,v;
//            printf("Vertices?\n");
//            scanf ("%d%d",&u,&v);
//            if(g.isEdge (u,v))printf("Edge\n");
//            else printf("Not edge\n");
//        }
//        else if(ch==4)
//        {
//            int u;
//            printf("Vertex?\n");
//            scanf ("%d",&u);
//            printf("Degree= %d\n",g.getDegree (u));
//        }

//        else if(ch==5)
//        {
//            int u;
//            printf("Vertex?\n");
//            scanf ("%d",&u);
//            g.printAdjVertices (u);
//        }
//        else if(ch==6)
//        {
//            g.printGraph();
//        }
//        else if(ch==7)
//        {
//            int u,v;
//            printf("Vertices?\n");
//            scanf ("%d%d",&u,&v);
//            if(g.hasCommonAdjacent (u,v))printf("Has common adjacent vertex\n");
//            else printf("No common adjacent vertex\n");
//        }
//        else if(ch==8)
//        {
//            int u,v;
//            printf("Vertices?\n");
//            scanf ("%d%d",&u,&v);
//            printf("%d\n",g.getDist (u,v));
//        }
//    }

//}
