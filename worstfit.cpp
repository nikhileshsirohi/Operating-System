#include <bits/stdc++.h>
using namespace std;
void worstFit(int blockSize[], int blocks, int processSize[], int processes)
{
    int allocation[processes];
    int occupied[blocks];
    for(int i = 0; i < processes; i++){
        allocation[i] = -1;
    }
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
    for (int i=0; i < processes; i++)
    {
	int indexPlaced = -1;
	for(int j = 0; j < blocks; j++)
	{
	    if(blockSize[j] >= processSize[i] && !occupied[j])
            {
                if (indexPlaced == -1)
                    indexPlaced = j;
                else if (blockSize[indexPlaced] < blockSize[j])
                    indexPlaced = j;
            }
        }
        if (indexPlaced != -1)
        {
            allocation[i] = indexPlaced;
            occupied[indexPlaced] = 1;
            blockSize[indexPlaced] -= processSize[i];
        }
    }
    cout<<"\nProcess No.\tProcess Size\tBlock no.\n";
    for (int i = 0; i < processes; i++)
    {
        cout<<i+1<<"\t\t\t"<<processSize[i]<<" \t\t\t";
        if (allocation[i] != -1)
            cout<<allocation[i] + 1<<endl;
        else
            cout<<"Not Allocated\n";
    }
}
int main()
{
    int b,p;
    cout<<"Enter total memeory block";
    cin>>b;
    int blockSize[b];
    for(int i=0;i<b;i++)
    {
        cout<<"Enter block "<<i+1<<" : ";
        cin>>blockSize[i];
    }
    cout<<"Enter total Process";
    cin>>p;
    int processSize[p];
    for(int i=0;i<p;i++)
    {
        cout<<"Enter process "<<i+1<<" : ";
        cin>>processSize[i];
    }
    worstFit(blockSize, b, processSize, p);
    
    return 0;
}