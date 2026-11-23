class ProductOfNumbers {
private :
    vector<int>v;
    int productK;
    // int start;
    // int productPrevK;
public:
    ProductOfNumbers() {
        this->productK=1;
        // this->productPrevK=1;
        // start=-1;
    }
    
    void add(int num) {
        this->v.push_back(num);
        this->productK*=num;
        // start++;

    }
    
    int getProduct(int k) {
        if(v.size()==k)return this->productK;
        int product=1;
        int end=v.size()-1;
        while(k--){
            product*=v[end--];
        }
        return product;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */