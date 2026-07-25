class MyCalendarTwo {
public:

    
    vector <pair<int , int>> books;
    vector <pair<int , int>> intersect;

    MyCalendarTwo() {
        
    }
    
    bool book(int startTime, int endTime) {

        for(auto &p : intersect){

            if(max(startTime , p.first) < min(endTime , p.second))
                return false;
        }

        for(auto &p : books){

            if(max(startTime , p.first) < min(endTime , p.second)){

                intersect.push_back({max(startTime , p.first) , min(endTime , p.second)});
            }
        }
        books.push_back({startTime , endTime});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(startTime,endTime);
 */