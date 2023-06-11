class SnapshotArray {
public:
    vector<map<int,int,greater<int>>> dp;
    int id = 0;
    SnapshotArray(int length) {
        dp.resize(length);
    }
    
    void set(int index, int val) {
        dp[index][id]= val;
    }
    
    int snap() {
        auto ret=id;
        id++;
        return ret;
    }
    
    int get(int index, int snap_id) {
        auto ptr=dp[index].lower_bound(snap_id);
        return ptr->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */