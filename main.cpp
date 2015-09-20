#include<stdio.h>
#include<iostream>
#define max(a,b) a>b?a:b
using namespace std;


int main()
{
    int t,T;
    scanf("%d",&T);
    for(t=1;t<=T;t++)
    {
        int n,i,maxvam=0,maxlyk=0,maxx,minn;
        scanf("%d",&n);
        int vam[100005]={0},lyk[100005]={0},aa[n],bb[n],rec[100005]={0};
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&aa[i],&bb[i]);
            rec[aa[i]]++;
            rec[bb[i]]++;

        }
        for(i=0;i<n;i++)
        {
            if(vam[aa[i]]==0 && lyk[aa[i]]==0 && vam[bb[i]]==0 && lyk[bb[i]]==0)
            {
                if(rec[aa[i]]>rec[bb[i]]){maxx=aa[i];minn=bb[i];}
                else {maxx=bb[i];minn=aa[i];}
                if(maxvam<maxlyk)
                {
                    vam[maxx]=1;
                    lyk[minn]=1;
                    maxvam++;
                    maxlyk++;

                }
                else
                {
                    vam[minn]=1;
                    lyk[maxx]=1;
                    maxvam++;
                    maxlyk++;
                }

            }
            else if(vam[aa[i]] && lyk[bb[i]]==0){lyk[bb[i]]=1;maxlyk++;}
            else if(vam[bb[i]] && lyk[aa[i]]==0){lyk[aa[i]]=1;maxlyk++;}
            else if(lyk[aa[i]] && vam[bb[i]]==0){vam[bb[i]]=1;maxvam++;}
            else if(lyk[bb[i]] && vam[aa[i]]==0){vam[aa[i]]=1;maxvam++;}
        }
        printf("Case %d: %d\n",t,maxvam>maxlyk?maxvam:maxlyk);
    }
}
