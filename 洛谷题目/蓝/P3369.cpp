#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
typedef __gnu_pbds::tree<pair<long long,long long>,__gnu_pbds::null_type,less<pair<long long,long long> >,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update> seet;
seet M;
long long n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int op;
    long long x;
    cin>>n;
    int k=0;
    while(n--){
        cin>>op>>x;
        switch(op){
            case 1:
            M.insert(make_pair(x,++k));
            break;
            case 2:{
                auto p=M.lower_bound(make_pair(x,0));
                M.erase(p);
            }
            break;
            case 3:
            cout<<M.order_of_key(make_pair(x,0))+1<<'\n';
            break;
            case 4:
            cout<<M.find_by_order(x-1)->first<<'\n';
            break;
            case 5:{
                auto p=M.lower_bound(make_pair(x,0));
                p--;
                cout<<p->first<<'\n';
            }
            break;
            case 6:
            cout<<M.upper_bound(make_pair(x,k+1))->first<<'\n';
            break;
        }
    }
    return 0;
}