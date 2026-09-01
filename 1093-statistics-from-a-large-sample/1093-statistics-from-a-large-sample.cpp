class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
       vector<double>ans;
       for(int i=0;i<256;i++){
        if(count[i]!=0){ans.push_back((double)i);
        break;}
       } 
       for(int i=255;i>=0;i--){
        if(count[i]!=0){ans.push_back((double)i);
        break;}
       }
      long double mean=0,median=0,mode=0;
        long  totalNumbers=0;
        long double totalSum=0;
       for(int i=0;i<256;i++){
        if(count[i]!=0){
            totalSum=totalSum+(double)i*count[i];
            totalNumbers=totalNumbers+count[i];
        }
       }
       ans.push_back(double(totalSum/totalNumbers));
if(totalNumbers%2==1){
    long  temp=(totalNumbers+1)/2;
    for(int i=0;i<256;i++){
        if(count[i]!=0){
            temp-=(double)count[i];
        }
        if(temp<=0){
            ans.push_back((double)i);
            break;
        }
    }

}
else{
    long temp = totalNumbers/2;
    long cumulative = 0;
    double m1 = -1, m2 = -1;

    for(int i=0;i<256;i++){
        cumulative += count[i];

        if(m1==-1 && cumulative>=temp) m1=i;
        if(cumulative>=temp+1){
            m2=i;
            break;
        }
    }
    ans.push_back((m1+m2)/2.0);
}
        int maxEl=*max_element(count.begin(),count.end());
        for(int i=0;i<256;i++){
            if(count[i]==maxEl){ans.push_back((double)i);
            break;}
        }
        return ans;
    } 
};