/*
 * File:main-10-90.cpp
 *  
 *
 * Author(s):
 *   Bapi Chatterjee <bapchatt@in.ibm.com>
 *   Sathya Peri <sathya_p@iith.ac.in>
 *   Muktikanta Sa   <cs15resch11012@iith.ac.in>
 *   Nandini Singhal <cs15mtech01004@iith.ac.in>
 *   
 * Description:
 *   Sequential implementation of a graph
 * Copyright (c) 2018.
 * last Updated: 31/07/2018
 *
*/
#include"SeqGraphDS.cpp"

 //ofstream couttt("graphinput.txt");
  typedef struct 
{
    int     secs;
    int     usecs;
}TIME_DIFF;

TIME_DIFF * my_difftime (struct timeval * start, struct timeval * end)
{
	TIME_DIFF * diff = (TIME_DIFF *) malloc ( sizeof (TIME_DIFF) );
 
	if (start->tv_sec == end->tv_sec) 
	{
        	diff->secs = 0;
        	diff->usecs = end->tv_usec - start->tv_usec;
    	}
   	else 
	{
        	diff->usecs = 1000000 - start->tv_usec;
        	diff->secs = end->tv_sec - (start->tv_sec + 1);
        	diff->usecs += end->tv_usec;
        	if (diff->usecs >= 1000000) 
		{
        	    diff->usecs -= 1000000;
	            diff->secs += 1;
	        }
	}
        return diff;
}


long vertexID;
double seconds;
struct timeval tv1, tv2;
TIME_DIFF * difference;
int  ops;






void call(slist G1)
{
        
	int u, v;
	while(true)
	{
		gettimeofday(&tv2,NULL);
		difference = my_difftime (&tv1, &tv2);
        	if(difference->secs >= seconds)
			break;
        	int op = rand()%1000;	
	       if(op >= 0 && op < 225 )
       		{
     				vertexID++;
				l1:	v = rand() % (vertexID);		
				if(v == 0)
					goto l1;
				G1.AddV(v);
				ops++;				
       		} 
	     	else if(op >= 225 && op <450 )
     		{
       			l2:	v = rand() % (vertexID);		
				if(v == 0)
					goto l2;
				G1.RemoveV(v);
        			ops++;				
       		}
		else if(op >= 450 && op < 675 )
		{
		l3:		u = (rand() % (vertexID));		
				v = (rand() % (vertexID));
				if(u == v || u == 0 || v == 0)	
					goto l3;
				G1.RemoveE(u,v); 
				ops++;				
		}
		else if(op >= 675 && op <900 )
		{
		l4:		u = (rand() % (vertexID));		
				v = (rand() % (vertexID));
				if(u == v || u == 0 || v == 0)	
					goto l3;
			     
				G1.AddE(u,v); 
				
				ops++;				
		}
		else if(op >= 900 && op < 950 )
		{
		l5:		u = (rand() % (vertexID));		
				v = (rand() % (vertexID));
				if(u == v || u == 0 || v == 0)		
					goto l5;
                              
				G1.ContainsE(u,v); 
				
				ops++;				
		}
		else if(op >= 950 && op < 1000 )
		{
		
		l6:		v = rand() % (vertexID);		
				if(v == 0)
					goto l2;
				G1.ContainsV(v);
        			ops++;		
		}
	} 		
}

int main(int argc, char*argv[])	
{
	slist sg;


	vertexID=1;
	int i;

	if(argc < 3)
	{
		cout << "Enter 2 command line arguments - #vertices initially, #time in seconds" << endl;
		return 0;
	}
	int initial_vertices = atoi(argv[1]); 		
	seconds = atoi(argv[2]);		
   	ops = 0;
	vertexID=initial_vertices + 1;		
        sg.init();
	sg.initGraph(initial_vertices);
	cout << "Initial graph with " << initial_vertices << " created." << endl;
    

   	int dig,temp; 
	double duration = 0.0;

	gettimeofday(&tv1,NULL);
	cout << "timer started . . ." << endl;
        call(sg);
	

	cout << seconds <<  " seconds elapsed" << endl;

    	cout << "Total operations: " << ops <<endl;


	return 0;
}

