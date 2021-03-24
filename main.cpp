 #include <string>



void getRev(std::string& str){

    int n = str.length();
    for(int i=0;i<n/2;i++){
        std::swap(str[i], str[n-1-i]);
    }
}

std::string add(const std::string &a , const std::string &b){
    std::string result;
    std::string one = a;
    std::string two = b;
    getRev(one); getRev(two);
    int i = 0, rem =0;
    bool same = false;
    std::string minimum;
    std::string rest;
    if(one.length()>two.length()){minimum=two; rest=one;}
    else if(two.length()>one.length()){minimum=one; rest=two;}
    else{same=true; minimum=one;}

    while(i!=minimum.length()){
        int temp = std::stoi(one.substr(i,1)) + std::stoi(two.substr(i,1)) + rem;
        rem = 0;
        while(temp>9) {
            temp-=10;rem++;
        }
        result += std::to_string(temp);
        i++;
    }

    if(!same){
        if(rem!=0) {
            bool over = false;
            while(rem!=0){
                std::string m = rest.substr(i++, 1);
                if(m.length()==0){result += std::to_string(rem);over= true;break;}
                int l = std::stoi(m)+rem;
                rem = 0;
                if(l>9){rem++;l-=10;}
                result += std::to_string(l);
            }
            if(!over)result += rest.substr(i);
        }
        else {
            std::string m = rest.substr(i);
            result += m;
        }
        getRev(result);
    }else{
        if(rem!=0) result += std::to_string(rem);
        getRev(result);
    }
    return result;
}
