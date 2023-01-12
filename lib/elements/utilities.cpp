#include "../../include/elements/utilities.h"

//OPERATORS

    bool game_elements::coordinates::operator==(const coordinates& coord) const{
        return (x_ == coord.get_x() && y_ == coord.get_y());
    }

    game_elements::coordinates& game_elements::coordinates::operator=(const coordinates& coord){
        x_ = coord.get_x();
        y_ = coord.get_y();
        return *this;
    }

//HELPER FUNCTIONS

    //return vertical distance
    int game_elements::vertical_distance(const coordinates& coord1, const coordinates& coord2){
        int dy = coord1.get_y() - coord2.get_y();
        if(dy > 0) return dy;
        return (dy)*(-1);
    }
    
    //return horizontal distance
    int game_elements::horizontal_distance(const coordinates& coord1, const coordinates& coord2){
        int dx = coord1.get_x() - coord2.get_x();
        if(dx > 0) return dx;
        return (dx)*(-1);
    }
    
    std::string game_elements::coord_to_str(int c){
        std::string out;
        if((c+1)/10 ==1) out += '1';
        out += '0' + (c+1)%10;
        return out;
    }

    char game_elements::coord_to_char(int c){
        char res = 'A' + c - 1;
        if(res >= 'J' ) res += 2;
        return res;
    }

    int game_elements::char_to_coord(char c){
        int res = c;
        if(res >= 'J' ) res -= 2;
        res += -'A';
        return res;
    }

    std::vector<game_elements::coordinates> game_elements::str_to_coord(const std::string& str){
        std::string first_half;
        std::string second_half;
        int i = 0;
        for (;str[i]!=' ';i++)
        {
            first_half += str[i];
        }
        second_half = str.substr(i + 1, str.length() - i - 1);
        int first_digit;
        int second_digit;
        std::vector<coordinates> res;
        res.push_back(coordinates());
        res.push_back(coordinates(-1,0));
        if(first_half.length()!= 2 and first_half.length()!=3) return res;
        if(second_half.length()!= 2 and second_half.length()!=3) return res;
        if(!isalpha(first_half[0]) or !isalpha(second_half[0])) return res;
        if(char_to_coord(first_half[0]) > 11 or char_to_coord(second_half[0]) > 11) return res;

        
        first_digit = first_half[1] - '1';
        second_digit = second_half[1] - '1';
        if(first_half.length() == 3) first_digit = 10*(first_half[1] - '0') + first_half[2] - '1';
        if(second_half.length() == 3) second_digit = 10*(second_half[1] - '0') + second_half[2] - '1';
        if(first_digit < 0 or second_digit < 0 or first_digit > 11 or second_digit > 11) return res;
        res[0] = coordinates(first_digit,char_to_coord(first_half[0]));
        res[1] = coordinates(second_digit,char_to_coord(second_half[0]));
        return res;
    }