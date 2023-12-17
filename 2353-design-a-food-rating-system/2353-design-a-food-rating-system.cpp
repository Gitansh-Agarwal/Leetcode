class FoodRatings {
public:
    map<string, map<int, set<string>>> cuisineRating;
    map<string, string> foodType;
    map<string, int> foodRating;
    
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        
        int n = foods.size();
        
        for(int i=0; i<n; i++){
            cuisineRating[cuisines[i]][ratings[i]].insert(foods[i]);
            foodType[foods[i]] = cuisines[i];
            foodRating[foods[i]] = ratings[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string cuisine = foodType[food];
        int oldRating = foodRating[food];
        
        cuisineRating[cuisine][oldRating].erase(food);
        
        //food_item set size after deletion
        if(cuisineRating[cuisine][oldRating].size() == 0){
            cuisineRating[cuisine].erase(oldRating);
        }
        
        //updating food to the newRating value
        foodRating[food] = newRating;
        cuisineRating[cuisine][newRating].insert(food);
    }
        
    
    string highestRated(string cuisine) {
        set<string> foodList = (*(cuisineRating[cuisine].rbegin())).second;
        return *(foodList.begin());
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */