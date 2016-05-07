#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main()
{
    int num_echo;
    cin >> num_echo;
    for(int i=0;i < num_echo;++i)
    {
        int num_moud, num_exam;
        cin >> num_moud >> num_exam;
        vector<multimap<int,multiset<int>>> moudle;
        int signal;
        vector<int> all_signal;
        for(int j = 0;j<num_exam;++j)
        {
            cin >> signal;
            all_signal.push_back(signal);
        }
        for(int j =0;j<num_moud;++j)
        {
            int input_signal,num_signal;      
            cin >> input_signal >> num_signal;
            moudle.push_back({{input_signal,multiset<int>()}});
            for(int k = 0;k < num_signal;++k)
            {
                int output_signal;
                cin >> output_signal;
                moudle[moudle.size()-1].begin()->second.insert(output_signal);
            } 
        }
        vector<int> moud_use_num(num_moud,0);
        for(int j=0;j<num_moud;++j)
        {
            for(int k=0;k<all_signal.size();++k)
            {
                auto p = moudle[j].find(all_signal[k]);
                if(p != moudle[j].end())
                {
                    ++moud_use_num[j];
                    for(auto l = p->second.begin();l != p->second.end();++l)
                        all_signal.push_back(*l);
                }
            }
        }
        for(auto e:moud_use_num)
            cout << e << " ";
        cout << endl;
    }
}
