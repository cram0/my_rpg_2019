#include <SFML/Graphics.h>
const sfIntRect boomerang_loop_rects[] = {
    { .left =  328, .top =  253, .width =   10, .height =   10, },
    { .left =  343, .top =  253, .width =   10, .height =   10, },
    { .left =  356, .top =  253, .width =   10, .height =   10, },
    { .left =  370, .top =  253, .width =   10, .height =   10, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect hud_boomerang_rects[] = {
    { .left =  276, .top =   74, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect hud_rects[] = {
    { .left =    0, .top =    0, .width =  256, .height =  224, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect hud_heart_empty_rects[] = {
    { .left =  259, .top =   56, .width =    7, .height =    7, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect hud_heart_full_rects[] = {
    { .left =  291, .top =   56, .width =    7, .height =    7, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect hud_heart_half_rects[] = {
    { .left =  257, .top =   56, .width =    7, .height =    7, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect hud_lantern_rects[] = {
    { .left =  259, .top =  159, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_attack_rects[] = {
    { .left =  510, .top =  282, .width =   20, .height =   23, },
    { .left =  542, .top =  286, .width =   22, .height =   24, },
    { .left =  571, .top =  282, .width =   20, .height =   31, },
    { .left =  598, .top =  283, .width =   20, .height =   31, },
    { .left =  624, .top =  284, .width =   28, .height =   29, },
    { .left =  661, .top =  284, .width =   32, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_boomerang_throw_rects[] = {
    { .left =  442, .top =  245, .width =   23, .height =   22, },
    { .left =  468, .top =  246, .width =   20, .height =   21, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_carry_idle_rects[] = {
    { .left =  159, .top =  137, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_carry_walk_rects[] = {
    { .left =  176, .top =  138, .width =   16, .height =   21, },
    { .left =  193, .top =  138, .width =   16, .height =   21, },
    { .left =  159, .top =  137, .width =   16, .height =   22, },
    { .left =  210, .top =  138, .width =   16, .height =   21, },
    { .left =  227, .top =  138, .width =   16, .height =   21, },
    { .left =  159, .top =  137, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_charge_super_attack_rects[] = {
    { .left =  701, .top =  284, .width =   19, .height =   29, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_idle_rects[] = {
    { .left =   90, .top =   13, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_idle_shield_rects[] = {
    { .left =    7, .top =  209, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_pull_rects[] = {
    { .left =  297, .top =   59, .width =   16, .height =   20, },
    { .left =  319, .top =   59, .width =   16, .height =   20, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_super_attack_rects[] = {
    { .left =  504, .top =  139, .width =   20, .height =   26, },
    { .left =  532, .top =  126, .width =   15, .height =   36, },
    { .left =  554, .top =  126, .width =   16, .height =   39, },
    { .left =  576, .top =  138, .width =   20, .height =   26, },
    { .left =  604, .top =  142, .width =   28, .height =   22, },
    { .left =  638, .top =  142, .width =   28, .height =   22, },
    { .left =  673, .top =  141, .width =   17, .height =   31, },
    { .left =  695, .top =  142, .width =   28, .height =   22, },
    { .left =  729, .top =  142, .width =   28, .height =   22, },
    { .left =  764, .top =  136, .width =   16, .height =   28, },
    { .left =  791, .top =  138, .width =   20, .height =   26, },
    { .left =  818, .top =  142, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_walk_rects[] = {
    { .left =  122, .top =   13, .width =   16, .height =   22, },
    { .left =  149, .top =   12, .width =   16, .height =   23, },
    { .left =  174, .top =   11, .width =   16, .height =   24, },
    { .left =  197, .top =   13, .width =   16, .height =   22, },
    { .left =  223, .top =   12, .width =   16, .height =   23, },
    { .left =  249, .top =   11, .width =   16, .height =   24, },
    { .left =  272, .top =   13, .width =   16, .height =   22, },
    { .left =  298, .top =   13, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_down_walk_shield_rects[] = {
    { .left =   33, .top =  209, .width =   16, .height =   22, },
    { .left =   59, .top =  208, .width =   16, .height =   23, },
    { .left =   82, .top =  207, .width =   16, .height =   24, },
    { .left =  106, .top =  209, .width =   16, .height =   22, },
    { .left =  131, .top =  209, .width =   16, .height =   22, },
    { .left =  154, .top =  208, .width =   16, .height =   23, },
    { .left =  175, .top =  207, .width =   16, .height =   24, },
    { .left =  198, .top =  209, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_falling_rects[] = {
    { .left =  283, .top =  170, .width =   22, .height =   22, },
    { .left =  317, .top =  175, .width =   16, .height =   16, },
    { .left =  341, .top =  178, .width =   13, .height =   13, },
    { .left =  363, .top =  183, .width =    8, .height =    8, },
    { .left =  378, .top =  184, .width =    7, .height =    7, },
    { .left =  389, .top =  188, .width =    3, .height =    3, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_attack_rects[] = {
    { .left =  519, .top =  192, .width =   16, .height =   23, },
    { .left =  546, .top =  191, .width =   23, .height =   24, },
    { .left =  574, .top =  194, .width =   29, .height =   21, },
    { .left =  611, .top =  194, .width =   31, .height =   21, },
    { .left =  652, .top =  193, .width =   28, .height =   29, },
    { .left =  681, .top =  193, .width =   23, .height =   31, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_boomerang_throw_rects[] = {
    { .left =  284, .top =  244, .width =   20, .height =   23, },
    { .left =  309, .top =  245, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_carry_idle_rects[] = {
    { .left =  159, .top =  168, .width =   16, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_carry_walk_rects[] = {
    { .left =  181, .top =  170, .width =   16, .height =   22, },
    { .left =  204, .top =  171, .width =   17, .height =   21, },
    { .left =  159, .top =  168, .width =   16, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_charge_super_attack_rects[] = {
    { .left =  708, .top =  192, .width =   24, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_idle_rects[] = {
    { .left =    4, .top =   56, .width =   16, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_idle_shield_rects[] = {
    { .left =  225, .top =  209, .width =   19, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_pull_rects[] = {
    { .left =  109, .top =  139, .width =   16, .height =   23, },
    { .left =  135, .top =  137, .width =   19, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_super_attack_rects[] = {
    { .left =  500, .top =   19, .width =   23, .height =   23, },
    { .left =  536, .top =   19, .width =   31, .height =   23, },
    { .left =  577, .top =   20, .width =   34, .height =   23, },
    { .left =  621, .top =   19, .width =   34, .height =   23, },
    { .left =  664, .top =   19, .width =   23, .height =   23, },
    { .left =  697, .top =   19, .width =   16, .height =   31, },
    { .left =  718, .top =   19, .width =   28, .height =   23, },
    { .left =  750, .top =   19, .width =   28, .height =   23, },
    { .left =  789, .top =   13, .width =   17, .height =   29, },
    { .left =  815, .top =   19, .width =   28, .height =   23, },
    { .left =  845, .top =   19, .width =   28, .height =   23, },
    { .left =  879, .top =   19, .width =   23, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_walk_rects[] = {
    { .left =   31, .top =   55, .width =   16, .height =   24, },
    { .left =   57, .top =   55, .width =   16, .height =   24, },
    { .left =   84, .top =   56, .width =   17, .height =   23, },
    { .left =  107, .top =   56, .width =   16, .height =   23, },
    { .left =  132, .top =   55, .width =   16, .height =   24, },
    { .left =  158, .top =   55, .width =   16, .height =   24, },
    { .left =  179, .top =   56, .width =   16, .height =   23, },
    { .left =  200, .top =   56, .width =   16, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_left_walk_shield_rects[] = {
    { .left =  249, .top =  208, .width =   19, .height =   24, },
    { .left =  277, .top =  208, .width =   18, .height =   24, },
    { .left =  301, .top =  209, .width =   19, .height =   23, },
    { .left =  326, .top =  209, .width =   19, .height =   23, },
    { .left =  351, .top =  208, .width =   19, .height =   24, },
    { .left =  402, .top =  208, .width =   18, .height =   24, },
    { .left =  425, .top =  209, .width =   19, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_attack_rects[] = {
    { .left =  519, .top =  192, .width =   16, .height =   23, },
    { .left =  546, .top =  191, .width =   23, .height =   24, },
    { .left =  574, .top =  194, .width =   29, .height =   21, },
    { .left =  611, .top =  194, .width =   31, .height =   21, },
    { .left =  652, .top =  193, .width =   28, .height =   29, },
    { .left =  681, .top =  193, .width =   23, .height =   31, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_boomerang_throw_rects[] = {
    { .left =  284, .top =  244, .width =   20, .height =   23, },
    { .left =  309, .top =  245, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_carry_idle_rects[] = {
    { .left =  159, .top =  168, .width =   16, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_carry_walk_rects[] = {
    { .left =  181, .top =  170, .width =   16, .height =   22, },
    { .left =  204, .top =  171, .width =   17, .height =   21, },
    { .left =  159, .top =  168, .width =   16, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_charge_super_attack_rects[] = {
    { .left =  708, .top =  192, .width =   24, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_idle_rects[] = {
    { .left =    4, .top =   56, .width =   16, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_idle_shield_rects[] = {
    { .left =  225, .top =  209, .width =   19, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_pull_rects[] = {
    { .left =  109, .top =  139, .width =   16, .height =   23, },
    { .left =  135, .top =  137, .width =   19, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_super_attack_rects[] = {
    { .left =  500, .top =   19, .width =   23, .height =   23, },
    { .left =  536, .top =   19, .width =   31, .height =   23, },
    { .left =  577, .top =   20, .width =   34, .height =   23, },
    { .left =  621, .top =   19, .width =   34, .height =   23, },
    { .left =  664, .top =   19, .width =   23, .height =   23, },
    { .left =  697, .top =   19, .width =   16, .height =   31, },
    { .left =  718, .top =   19, .width =   28, .height =   23, },
    { .left =  750, .top =   19, .width =   28, .height =   23, },
    { .left =  789, .top =   13, .width =   17, .height =   29, },
    { .left =  815, .top =   19, .width =   28, .height =   23, },
    { .left =  845, .top =   19, .width =   28, .height =   23, },
    { .left =  879, .top =   19, .width =   23, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_walk_rects[] = {
    { .left =   31, .top =   55, .width =   16, .height =   24, },
    { .left =   57, .top =   55, .width =   16, .height =   24, },
    { .left =   84, .top =   56, .width =   17, .height =   23, },
    { .left =  107, .top =   56, .width =   16, .height =   23, },
    { .left =  132, .top =   55, .width =   16, .height =   24, },
    { .left =  158, .top =   55, .width =   16, .height =   24, },
    { .left =  179, .top =   56, .width =   16, .height =   23, },
    { .left =  200, .top =   56, .width =   16, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_right_walk_shield_rects[] = {
    { .left =  249, .top =  208, .width =   19, .height =   24, },
    { .left =  277, .top =  208, .width =   18, .height =   24, },
    { .left =  301, .top =  209, .width =   19, .height =   23, },
    { .left =  326, .top =  209, .width =   19, .height =   23, },
    { .left =  351, .top =  208, .width =   19, .height =   24, },
    { .left =  402, .top =  208, .width =   18, .height =   24, },
    { .left =  425, .top =  209, .width =   19, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_sword_rise_rects[] = {
    { .left =  284, .top =  124, .width =   17, .height =   35, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_attack_rects[] = {
    { .left =  517, .top =  243, .width =   22, .height =   22, },
    { .left =  546, .top =  235, .width =   22, .height =   30, },
    { .left =  582, .top =  230, .width =   20, .height =   35, },
    { .left =  611, .top =  235, .width =   24, .height =   30, },
    { .left =  643, .top =  242, .width =   32, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_boomerang_throw_rects[] = {
    { .left =  387, .top =  243, .width =   23, .height =   23, },
    { .left =  415, .top =  244, .width =   19, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_carry_idle_rects[] = {
    { .left =   10, .top =  177, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_carry_walk_rects[] = {
    { .left =   36, .top =  178, .width =   16, .height =   21, },
    { .left =   60, .top =  177, .width =   16, .height =   22, },
    { .left =   82, .top =  178, .width =   16, .height =   21, },
    { .left =   60, .top =  177, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_charge_super_attack_rects[] = {
    { .left =  686, .top =  239, .width =   19, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_idle_rects[] = {
    { .left =    3, .top =   97, .width =   16, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_idle_shield_rects[] = {
    { .left =    7, .top =  239, .width =   17, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_pull_rects[] = {
    { .left =  232, .top =   98, .width =   16, .height =   21, },
    { .left =  253, .top =   99, .width =   16, .height =   20, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_super_attack_rects[] = {
    { .left =  487, .top =   60, .width =   20, .height =   27, },
    { .left =  516, .top =   61, .width =   15, .height =   35, },
    { .left =  541, .top =   60, .width =   17, .height =   38, },
    { .left =  568, .top =   60, .width =   17, .height =   38, },
    { .left =  595, .top =   60, .width =   20, .height =   27, },
    { .left =  620, .top =   60, .width =   28, .height =   22, },
    { .left =  657, .top =   54, .width =   16, .height =   28, },
    { .left =  681, .top =   60, .width =   28, .height =   22, },
    { .left =  720, .top =   60, .width =   16, .height =   31, },
    { .left =  746, .top =   61, .width =   17, .height =   31, },
    { .left =  767, .top =   61, .width =   20, .height =   27, },
    { .left =  797, .top =   61, .width =   17, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_walk_rects[] = {
    { .left =   30, .top =   97, .width =   16, .height =   22, },
    { .left =   57, .top =   96, .width =   16, .height =   23, },
    { .left =   81, .top =   95, .width =   16, .height =   24, },
    { .left =  108, .top =   97, .width =   16, .height =   22, },
    { .left =  131, .top =   96, .width =   16, .height =   23, },
    { .left =  156, .top =   95, .width =   16, .height =   24, },
    { .left =  180, .top =   97, .width =   16, .height =   22, },
    { .left =  204, .top =   96, .width =   16, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect link_up_walk_shield_rects[] = {
    { .left =   32, .top =  237, .width =   17, .height =   24, },
    { .left =   55, .top =  239, .width =   17, .height =   22, },
    { .left =   78, .top =  239, .width =   17, .height =   22, },
    { .left =  101, .top =  238, .width =   17, .height =   23, },
    { .left =  126, .top =  239, .width =   17, .height =   22, },
    { .left =  148, .top =  237, .width =   17, .height =   24, },
    { .left =  172, .top =  240, .width =   17, .height =   22, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_down_idle_rects[] = {
    { .left =  128, .top =   75, .width =   22, .height =   33, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_down_walk_rects[] = {
    { .left =  155, .top =   75, .width =   22, .height =   34, },
    { .left =  182, .top =   74, .width =   22, .height =   35, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_falling_rects[] = {
    { .left =  361, .top =  281, .width =   22, .height =   22, },
    { .left =  384, .top =  280, .width =   16, .height =   16, },
    { .left =  402, .top =  282, .width =   13, .height =   13, },
    { .left =  416, .top =  288, .width =    8, .height =    8, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_left_idle_rects[] = {
    { .left =   11, .top =   82, .width =   29, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_left_walk_rects[] = {
    { .left =   10, .top =    7, .width =   32, .height =   28, },
    { .left =   48, .top =    8, .width =   27, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_right_idle_rects[] = {
    { .left =   11, .top =   82, .width =   29, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_right_walk_rects[] = {
    { .left =   10, .top =    7, .width =   32, .height =   28, },
    { .left =   48, .top =    8, .width =   27, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_up_idle_rects[] = {
    { .left =  285, .top =   81, .width =   22, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_bk_up_walk_rects[] = {
    { .left =  233, .top =   82, .width =   22, .height =   26, },
    { .left =  259, .top =   82, .width =   22, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_crab_idle_rects[] = {
    { .left =  658, .top =  130, .width =   12, .height =   14, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_crab_walk_rects[] = {
    { .left =  624, .top =  131, .width =   16, .height =   13, },
    { .left =  642, .top =  131, .width =   12, .height =   13, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_down_idle_rects[] = {
    { .left =   16, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_down_look_left_rects[] = {
    { .left =   76, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_down_look_right_rects[] = {
    { .left =   56, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_down_walk_rects[] = {
    { .left =   16, .top =   44, .width =   16, .height =   28, },
    { .left =   36, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_falling_rects[] = {
    { .left =  217, .top =  281, .width =   22, .height =   22, },
    { .left =  240, .top =  280, .width =   16, .height =   16, },
    { .left =  258, .top =  282, .width =   13, .height =   13, },
    { .left =  272, .top =  288, .width =    8, .height =    8, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_left_idle_rects[] = {
    { .left =  203, .top =   44, .width =   18, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_left_look_down_rects[] = {
    { .left =  225, .top =   44, .width =   17, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_left_look_up_rects[] = {
    { .left =  246, .top =   44, .width =   17, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_left_walk_rects[] = {
    { .left =  181, .top =   44, .width =   18, .height =   28, },
    { .left =  203, .top =   44, .width =   18, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_right_idle_rects[] = {
    { .left =   95, .top =   44, .width =   18, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_right_look_down_rects[] = {
    { .left =  155, .top =   44, .width =   17, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_right_look_up_rects[] = {
    { .left =  137, .top =   44, .width =   17, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_right_walk_rects[] = {
    { .left =   95, .top =   44, .width =   18, .height =   28, },
    { .left =  115, .top =   44, .width =   18, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_up_idle_rects[] = {
    { .left =  265, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_up_look_left_rects[] = {
    { .left =  305, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_up_look_right_rects[] = {
    { .left =  325, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_gk_up_walk_rects[] = {
    { .left =  265, .top =   44, .width =   16, .height =   28, },
    { .left =  285, .top =   44, .width =   16, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_down_idle_rects[] = {
    { .left =  442, .top =  128, .width =   12, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_down_walk_rects[] = {
    { .left =  490, .top =  129, .width =   12, .height =   15, },
    { .left =  416, .top =  129, .width =   12, .height =   15, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_left_idle_rects[] = {
    { .left =  505, .top =  128, .width =   15, .height =   16, },
    { .left =  520, .top =  128, .width =   15, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_left_walk_rects[] = {
    { .left =  456, .top =  130, .width =   16, .height =   12, },
    { .left =  472, .top =  130, .width =   16, .height =   11, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_right_idle_rects[] = {
    { .left =  505, .top =  128, .width =   15, .height =   16, },
    { .left =  520, .top =  128, .width =   15, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_right_walk_rects[] = {
    { .left =  456, .top =  130, .width =   16, .height =   12, },
    { .left =  472, .top =  130, .width =   16, .height =   11, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_up_idle_rects[] = {
    { .left =  442, .top =  128, .width =   12, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_mouse_up_walk_rects[] = {
    { .left =  490, .top =  129, .width =   12, .height =   15, },
    { .left =  416, .top =  129, .width =   12, .height =   15, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_down_idle_rects[] = {
    { .left =  546, .top =  128, .width =   13, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_down_walk_rects[] = {
    { .left =  546, .top =  128, .width =   13, .height =   16, },
    { .left =  678, .top =  128, .width =   13, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_left_idle_rects[] = {
    { .left =  576, .top =  128, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_left_walk_rects[] = {
    { .left =  576, .top =  128, .width =   16, .height =   16, },
    { .left =  593, .top =  128, .width =   15, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_right_idle_rects[] = {
    { .left =  576, .top =  128, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_right_walk_rects[] = {
    { .left =  576, .top =  128, .width =   16, .height =   16, },
    { .left =  593, .top =  128, .width =   15, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_up_idle_rects[] = {
    { .left =  562, .top =  128, .width =   12, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_serpent_up_walk_rects[] = {
    { .left =  562, .top =  128, .width =   12, .height =   16, },
    { .left =  693, .top =  128, .width =   12, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_down_attack_rects[] = {
    { .left =   16, .top =  590, .width =   26, .height =   27, },
    { .left =  184, .top =  599, .width =   40, .height =   25, },
    { .left =  238, .top =  597, .width =   25, .height =   30, },
    { .left =  289, .top =  603, .width =   40, .height =   25, },
    { .left =   11, .top =  640, .width =   41, .height =   32, },
    { .left =   77, .top =  631, .width =   25, .height =   42, },
    { .left =  127, .top =  636, .width =   22, .height =   36, },
    { .left =  180, .top =  644, .width =   26, .height =   25, },
    { .left =  241, .top =  643, .width =   23, .height =   29, },
    { .left =  293, .top =  647, .width =   40, .height =   25, },
    { .left =   11, .top =  692, .width =   41, .height =   31, },
    { .left =   74, .top =  682, .width =   26, .height =   42, },
    { .left =  129, .top =  684, .width =   22, .height =   37, },
    { .left =  181, .top =  692, .width =   22, .height =   26, },
    { .left =  243, .top =  693, .width =   29, .height =   29, },
    { .left =  297, .top =  692, .width =   41, .height =   31, },
    { .left =    8, .top =  735, .width =   26, .height =   42, },
    { .left =   72, .top =  734, .width =   27, .height =   43, },
    { .left =  119, .top =  737, .width =   36, .height =   36, },
    { .left =  169, .top =  747, .width =   43, .height =   25, },
    { .left =  231, .top =  737, .width =   40, .height =   34, },
    { .left =  300, .top =  732, .width =   26, .height =   54, },
    { .left =    6, .top =  789, .width =   27, .height =   61, },
    { .left =   74, .top =  792, .width =   50, .height =   48, },
    { .left =  133, .top =  795, .width =   58, .height =   34, },
    { .left =  197, .top =  794, .width =   59, .height =   25, },
    { .left =  286, .top =  801, .width =   55, .height =   32, },
    { .left =    8, .top =  873, .width =   47, .height =   41, },
    { .left =   83, .top =  872, .width =   38, .height =   44, },
    { .left =  143, .top =  871, .width =   29, .height =   44, },
    { .left =  203, .top =  886, .width =   26, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_down_idle_rects[] = {
    { .left =   16, .top =  590, .width =   26, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_down_walk_rects[] = {
    { .left =   73, .top =  593, .width =   26, .height =   26, },
    { .left =  127, .top =  596, .width =   26, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_left_attack_rects[] = {
    { .left =   60, .top =   12, .width =   16, .height =   27, },
    { .left =   84, .top =   11, .width =   29, .height =   27, },
    { .left =  129, .top =   10, .width =   18, .height =   33, },
    { .left =  167, .top =   11, .width =   25, .height =   30, },
    { .left =  210, .top =   12, .width =   31, .height =   27, },
    { .left =  258, .top =    7, .width =   27, .height =   35, },
    { .left =  305, .top =    4, .width =   16, .height =   40, },
    { .left =  337, .top =    7, .width =   22, .height =   38, },
    { .left =    2, .top =   49, .width =   30, .height =   29, },
    { .left =   54, .top =   51, .width =   19, .height =   33, },
    { .left =   95, .top =   55, .width =   29, .height =   27, },
    { .left =  132, .top =   55, .width =   31, .height =   27, },
    { .left =  184, .top =   50, .width =   27, .height =   35, },
    { .left =  234, .top =   46, .width =   21, .height =   39, },
    { .left =  272, .top =   58, .width =   30, .height =   29, },
    { .left =  313, .top =   60, .width =   28, .height =   27, },
    { .left =   12, .top =   91, .width =   18, .height =   33, },
    { .left =   56, .top =   94, .width =   29, .height =   27, },
    { .left =   98, .top =  102, .width =   31, .height =   27, },
    { .left =  139, .top =   96, .width =   27, .height =   34, },
    { .left =  181, .top =   93, .width =   21, .height =   39, },
    { .left =  219, .top =   97, .width =   27, .height =   35, },
    { .left =  259, .top =  106, .width =   30, .height =   27, },
    { .left =  303, .top =  105, .width =   29, .height =   27, },
    { .left =   11, .top =  136, .width =   27, .height =   34, },
    { .left =   56, .top =  131, .width =   22, .height =   38, },
    { .left =   99, .top =  134, .width =   16, .height =   40, },
    { .left =  139, .top =  137, .width =   21, .height =   39, },
    { .left =  177, .top =  144, .width =   30, .height =   30, },
    { .left =  224, .top =  146, .width =   36, .height =   27, },
    { .left =  282, .top =  146, .width =   36, .height =   32, },
    { .left =   10, .top =  192, .width =   16, .height =   53, },
    { .left =   57, .top =  195, .width =   24, .height =   54, },
    { .left =  102, .top =  197, .width =   32, .height =   53, },
    { .left =  151, .top =  197, .width =   47, .height =   46, },
    { .left =  220, .top =  200, .width =   60, .height =   33, },
    { .left =  295, .top =  200, .width =   56, .height =   34, },
    { .left =    8, .top =  264, .width =   45, .height =   47, },
    { .left =   69, .top =  259, .width =   39, .height =   51, },
    { .left =  133, .top =  260, .width =   26, .height =   54, },
    { .left =  189, .top =  261, .width =   16, .height =   52, },
    { .left =  219, .top =  276, .width =   30, .height =   33, },
    { .left =  295, .top =  284, .width =   16, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_left_idle_rects[] = {
    { .left =    4, .top =   11, .width =   16, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_left_walk_rects[] = {
    { .left =    4, .top =   11, .width =   16, .height =   27, },
    { .left =   33, .top =   12, .width =   16, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_right_attack_rects[] = {
    { .left =   60, .top =   12, .width =   16, .height =   27, },
    { .left =   84, .top =   11, .width =   29, .height =   27, },
    { .left =  129, .top =   10, .width =   18, .height =   33, },
    { .left =  167, .top =   11, .width =   25, .height =   30, },
    { .left =  210, .top =   12, .width =   31, .height =   27, },
    { .left =  258, .top =    7, .width =   27, .height =   35, },
    { .left =  305, .top =    4, .width =   16, .height =   40, },
    { .left =  337, .top =    7, .width =   22, .height =   38, },
    { .left =    2, .top =   49, .width =   30, .height =   29, },
    { .left =   54, .top =   51, .width =   19, .height =   33, },
    { .left =   95, .top =   55, .width =   29, .height =   27, },
    { .left =  132, .top =   55, .width =   31, .height =   27, },
    { .left =  184, .top =   50, .width =   27, .height =   35, },
    { .left =  234, .top =   46, .width =   21, .height =   39, },
    { .left =  272, .top =   58, .width =   30, .height =   29, },
    { .left =  313, .top =   60, .width =   28, .height =   27, },
    { .left =   12, .top =   91, .width =   18, .height =   33, },
    { .left =   56, .top =   94, .width =   29, .height =   27, },
    { .left =   98, .top =  102, .width =   31, .height =   27, },
    { .left =  139, .top =   96, .width =   27, .height =   34, },
    { .left =  181, .top =   93, .width =   21, .height =   39, },
    { .left =  219, .top =   97, .width =   27, .height =   35, },
    { .left =  259, .top =  106, .width =   30, .height =   27, },
    { .left =  303, .top =  105, .width =   29, .height =   27, },
    { .left =   11, .top =  136, .width =   27, .height =   34, },
    { .left =   56, .top =  131, .width =   22, .height =   38, },
    { .left =   99, .top =  134, .width =   16, .height =   40, },
    { .left =  139, .top =  137, .width =   21, .height =   39, },
    { .left =  177, .top =  144, .width =   30, .height =   30, },
    { .left =  224, .top =  146, .width =   36, .height =   27, },
    { .left =  282, .top =  146, .width =   36, .height =   32, },
    { .left =   10, .top =  192, .width =   16, .height =   53, },
    { .left =   57, .top =  195, .width =   24, .height =   54, },
    { .left =  102, .top =  197, .width =   32, .height =   53, },
    { .left =  151, .top =  197, .width =   47, .height =   46, },
    { .left =  220, .top =  200, .width =   60, .height =   33, },
    { .left =  295, .top =  200, .width =   56, .height =   34, },
    { .left =    8, .top =  264, .width =   45, .height =   47, },
    { .left =   69, .top =  259, .width =   39, .height =   51, },
    { .left =  133, .top =  260, .width =   26, .height =   54, },
    { .left =  189, .top =  261, .width =   16, .height =   52, },
    { .left =  219, .top =  276, .width =   30, .height =   33, },
    { .left =  295, .top =  284, .width =   16, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_right_idle_rects[] = {
    { .left =    4, .top =   11, .width =   16, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_right_walk_rects[] = {
    { .left =    4, .top =   11, .width =   16, .height =   27, },
    { .left =   33, .top =   12, .width =   16, .height =   27, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_up_attack_rects[] = {
    { .left =  179, .top =  343, .width =   27, .height =   25, },
    { .left =  214, .top =  340, .width =   40, .height =   25, },
    { .left =  285, .top =  343, .width =   25, .height =   25, },
    { .left =    7, .top =  398, .width =   28, .height =   40, },
    { .left =   57, .top =  399, .width =   35, .height =   38, },
    { .left =  116, .top =  404, .width =   35, .height =   29, },
    { .left =  179, .top =  400, .width =   29, .height =   31, },
    { .left =  230, .top =  399, .width =   24, .height =   30, },
    { .left =  290, .top =  391, .width =   22, .height =   39, },
    { .left =    4, .top =  462, .width =   34, .height =   38, },
    { .left =   57, .top =  473, .width =   43, .height =   25, },
    { .left =  127, .top =  474, .width =   24, .height =   25, },
    { .left =  184, .top =  465, .width =   22, .height =   35, },
    { .left =  225, .top =  466, .width =   41, .height =   25, },
    { .left =  289, .top =  466, .width =   24, .height =   34, },
    { .left =   13, .top =  532, .width =   38, .height =   25, },
    { .left =   69, .top =  512, .width =   39, .height =   55, },
    { .left =  127, .top =  509, .width =   26, .height =   67, },
    { .left =  182, .top =  508, .width =   22, .height =   71, },
    { .left =  229, .top =  509, .width =   29, .height =   70, },
    { .left =  267, .top =  546, .width =   46, .height =   29, },
    { .left =  326, .top =  549, .width =   27, .height =   25, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_up_idle_rects[] = {
    { .left =    5, .top =  344, .width =   27, .height =   25, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_trooper_up_walk_rects[] = {
    { .left =   61, .top =  344, .width =   27, .height =   24, },
    { .left =  119, .top =  344, .width =   27, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_yk_down_idle_rects[] = {
    { .left =  210, .top =  120, .width =   25, .height =   30, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_yk_left_idle_rects[] = {
    { .left =  293, .top =  122, .width =   21, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_yk_right_idle_rects[] = {
    { .left =  239, .top =  122, .width =   21, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect monster_yk_up_idle_rects[] = {
    { .left =  264, .top =  122, .width =   25, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_priest_down_idle_rects[] = {
    { .left =  248, .top =  521, .width =   16, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_priest_left_idle_rects[] = {
    { .left =  289, .top =  521, .width =   14, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_priest_right_idle_rects[] = {
    { .left =  289, .top =  521, .width =   14, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_priest_up_idle_rects[] = {
    { .left =  328, .top =  521, .width =   16, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_dead_no_sword_rects[] = {
    { .left =  203, .top =  321, .width =   26, .height =   24, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_dead_sword_rects[] = {
    { .left =  202, .top =  279, .width =   28, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_down_idle_rects[] = {
    { .left =  126, .top =  280, .width =   20, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_down_walk_rects[] = {
    { .left =  126, .top =  280, .width =   20, .height =   26, },
    { .left =  126, .top =  320, .width =   20, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_left_idle_rects[] = {
    { .left =  166, .top =  280, .width =   19, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_left_walk_rects[] = {
    { .left =  166, .top =  280, .width =   19, .height =   26, },
    { .left =  165, .top =  320, .width =   21, .height =   25, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_right_idle_rects[] = {
    { .left =  166, .top =  280, .width =   19, .height =   26, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_uncle_right_walk_rects[] = {
    { .left =  166, .top =  280, .width =   19, .height =   26, },
    { .left =  165, .top =  320, .width =   21, .height =   25, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_down_idle_rects[] = {
    { .left =  128, .top =   81, .width =   16, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_down_walk_rects[] = {
    { .left =  128, .top =   81, .width =   16, .height =   23, },
    { .left =  128, .top =  121, .width =   16, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_laying_down_rects[] = {
    { .left =  164, .top =  165, .width =   24, .height =   15, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_left_idle_rects[] = {
    { .left =  169, .top =   81, .width =   14, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_left_walk_rects[] = {
    { .left =  169, .top =   81, .width =   14, .height =   23, },
    { .left =  169, .top =  121, .width =   13, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_levitating_rects[] = {
    { .left =  205, .top =  165, .width =   22, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_right_idle_rects[] = {
    { .left =  169, .top =   81, .width =   14, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_right_walk_rects[] = {
    { .left =  169, .top =   81, .width =   14, .height =   23, },
    { .left =  169, .top =  121, .width =   13, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_up_idle_rects[] = {
    { .left =  208, .top =   81, .width =   15, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect npc_zelda_up_walk_rects[] = {
    { .left =  208, .top =   81, .width =   15, .height =   23, },
    { .left =  208, .top =  121, .width =   15, .height =   23, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_boomerang_rects[] = {
    { .left =  167, .top =   78, .width =   14, .height =   14, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_bush_rects[] = {
    { .left =   22, .top =  102, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_chest_closed_rects[] = {
    { .left =  110, .top =  234, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_chest_open_rects[] = {
    { .left =  131, .top =  234, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_ground_torch_off_rects[] = {
    { .left =   80, .top =  268, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_ground_torch_on_rects[] = {
    { .left =   99, .top =  268, .width =   16, .height =   16, },
    { .left =  118, .top =  268, .width =   16, .height =   16, },
    { .left =  137, .top =  268, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_ground_torch_sanctuary_rects[] = {
    { .left =   17, .top =  260, .width =   16, .height =   31, },
    { .left =   37, .top =  260, .width =   16, .height =   31, },
    { .left =   59, .top =  260, .width =   16, .height =   31, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_heart_container_rects[] = {
    { .left =  153, .top =   30, .width =   14, .height =   13, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_heart_container_dialog_rects[] = {
    { .left =  171, .top =   29, .width =   16, .height =   14, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_key_big_rects[] = {
    { .left =  146, .top =    5, .width =   14, .height =   17, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_key_simple_rects[] = {
    { .left =  166, .top =    6, .width =    8, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_lamp_rects[] = {
    { .left =  186, .top =   78, .width =   12, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_map_rects[] = {
    { .left =  180, .top =    5, .width =   16, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_pot_rects[] = {
    { .left =   60, .top =  171, .width =   12, .height =   13, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_rupee_blue_rects[] = {
    { .left =   67, .top =   78, .width =    8, .height =   14, },
    { .left =   80, .top =   78, .width =    8, .height =   14, },
    { .left =   93, .top =   78, .width =    8, .height =   14, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_rupee_green_rects[] = {
    { .left =   30, .top =   78, .width =    8, .height =   14, },
    { .left =   43, .top =   78, .width =    8, .height =   14, },
    { .left =   56, .top =   78, .width =    8, .height =   14, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_rupee_red_rects[] = {
    { .left =  105, .top =   78, .width =    8, .height =   14, },
    { .left =  118, .top =   78, .width =    8, .height =   14, },
    { .left =  131, .top =   78, .width =    8, .height =   14, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect object_wall_torch_rects[] = {
    { .left =  161, .top =  267, .width =   18, .height =   16, },
    { .left =  181, .top =  267, .width =   18, .height =   16, },
    { .left =  201, .top =  267, .width =   18, .height =   16, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect rain_flash_rects[] = {
    { .left =    2, .top =  523, .width =  256, .height =  223, },
    { .left =  265, .top =  523, .width =  256, .height =  223, },
    { .left =    2, .top =  751, .width =  256, .height =  223, },
    { .left =  265, .top =  750, .width =  256, .height =  223, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect rain_noflash_rects[] = {
    { .left =    2, .top =   33, .width =  256, .height =  233, },
    { .left =  266, .top =   33, .width =  256, .height =  233, },
    { .left =    2, .top =  263, .width =  256, .height =  233, },
    { .left =  266, .top =  263, .width =  256, .height =  223, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect sfx_bush_slash_rects[] = {
    { .left =    7, .top =   17, .width =   29, .height =   43, },
    { .left =   37, .top =   17, .width =   29, .height =   43, },
    { .left =   67, .top =   17, .width =   29, .height =   43, },
    { .left =   97, .top =   17, .width =   29, .height =   43, },
    { .left =  127, .top =   17, .width =   29, .height =   43, },
    { .left =  157, .top =   17, .width =   29, .height =   43, },
    { .left =  187, .top =   17, .width =   29, .height =   43, },
    { .left =  217, .top =   17, .width =   29, .height =   43, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect sfx_kill_enemy_rects[] = {
    { .left =    7, .top =  128, .width =   26, .height =   32, },
    { .left =   34, .top =  128, .width =   26, .height =   32, },
    { .left =   61, .top =  128, .width =   26, .height =   32, },
    { .left =   88, .top =  128, .width =   26, .height =   32, },
    { .left =  115, .top =  128, .width =   26, .height =   32, },
    { .left =  142, .top =  128, .width =   26, .height =   32, },
    { .left =  169, .top =  128, .width =   26, .height =   32, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect sfx_pot_explode_rects[] = {
    { .left =    7, .top =   83, .width =   30, .height =   28, },
    { .left =   38, .top =   83, .width =   30, .height =   28, },
    { .left =   69, .top =   83, .width =   30, .height =   28, },
    { .left =  100, .top =   83, .width =   30, .height =   28, },
    { .left =  131, .top =   83, .width =   30, .height =   28, },
    { .left =  162, .top =   83, .width =   30, .height =   28, },
    { .left =  193, .top =   83, .width =   30, .height =   28, },
    { .left =  224, .top =   83, .width =   30, .height =   28, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect small_shine_rects[] = {
    { .left =    0, .top =    0, .width =   15, .height =   15, },
    { .left =   15, .top =    0, .width =   15, .height =   15, },
    { .left =   30, .top =    0, .width =   15, .height =   15, },
    { .left =   45, .top =    0, .width =   15, .height =   15, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect transition_circle_rects[] = {
    { .left =    2, .top =    2, .width =  257, .height =  223, },
    { .left =  265, .top =    3, .width =  256, .height =  223, },
    { .left =    2, .top =  233, .width =  257, .height =  223, },
    { .left =  265, .top =  232, .width =  256, .height =  223, },
    { .left =    2, .top =  461, .width =  257, .height =  223, },
    { .left =  265, .top =  461, .width =  259, .height =  223, },
    { .left =    3, .top =  694, .width =  257, .height =  223, },
    { .left =  267, .top =  694, .width =  256, .height =  223, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

const sfIntRect triforce_rects[] = {
    { .left =    0, .top =    0, .width =  175, .height =  160, },
    { .left =  176, .top =    0, .width =  175, .height =  160, },
    { .left =  352, .top =    0, .width =  175, .height =  160, },
    { .left =  528, .top =    0, .width =  175, .height =  160, },
    { .left =  704, .top =    0, .width =  175, .height =  160, },
    { .left =  880, .top =    0, .width =  175, .height =  160, },
    { .left = 1056, .top =    0, .width =  175, .height =  160, },
    { .left = 1232, .top =    0, .width =  175, .height =  160, },
    { .left =    0, .top =  160, .width =  175, .height =  160, },
    { .left =  176, .top =  160, .width =  175, .height =  160, },
    { .left =  352, .top =  160, .width =  175, .height =  160, },
    { .left =  528, .top =  160, .width =  175, .height =  160, },
    { .left =  704, .top =  160, .width =  175, .height =  160, },
    { .left =  880, .top =  160, .width =  175, .height =  160, },
    { .left = 1056, .top =  160, .width =  175, .height =  160, },
    { .left = 1232, .top =  160, .width =  175, .height =  160, },
    { .left =    0, .top =  320, .width =  175, .height =  160, },
    { .left =  176, .top =  320, .width =  175, .height =  160, },
    { .left =  352, .top =  320, .width =  175, .height =  160, },
    { .left =  528, .top =  320, .width =  175, .height =  160, },
    { .left =  704, .top =  320, .width =  175, .height =  160, },
    { .left =  880, .top =  320, .width =  175, .height =  160, },
    { .left = 1056, .top =  320, .width =  175, .height =  160, },
    { .left = 1232, .top =  320, .width =  175, .height =  160, },
    { .left =    0, .top =  480, .width =  175, .height =  160, },
    { .left =  176, .top =  480, .width =  175, .height =  160, },
    { .left =  352, .top =  480, .width =  175, .height =  160, },
    { .left =  528, .top =  480, .width =  175, .height =  160, },
    { .left =  704, .top =  480, .width =  175, .height =  160, },
    { .left =  880, .top =  480, .width =  175, .height =  160, },
    { .left = 1056, .top =  480, .width =  175, .height =  160, },
    { .left = 1232, .top =  480, .width =  175, .height =  160, },
    { .left =    0, .top =  640, .width =  175, .height =  160, },
    { .left =  176, .top =  640, .width =  175, .height =  160, },
    { .left =  352, .top =  640, .width =  175, .height =  160, },
    { .left =  528, .top =  640, .width =  175, .height =  160, },
    { .left =  704, .top =  640, .width =  175, .height =  160, },
    { .left =  880, .top =  640, .width =  175, .height =  160, },
    { .left = 1056, .top =  640, .width =  175, .height =  160, },
    { .left = 1232, .top =  640, .width =  175, .height =  160, },
    { .left =    0, .top =  800, .width =  175, .height =  160, },
    { .left =  176, .top =  800, .width =  175, .height =  160, },
    { .left =  352, .top =  800, .width =  175, .height =  160, },
    { .left =  528, .top =  800, .width =  175, .height =  160, },
    { .left =  704, .top =  800, .width =  175, .height =  160, },
    { .left =  880, .top =  800, .width =  175, .height =  160, },
    { .left = 1056, .top =  800, .width =  175, .height =  160, },
    { .left = 1232, .top =  800, .width =  175, .height =  160, },
    { .left =    0, .top =  960, .width =  175, .height =  160, },
    { .left =  176, .top =  960, .width =  175, .height =  160, },
    { .left =  352, .top =  960, .width =  175, .height =  160, },
    { .left =  528, .top =  960, .width =  175, .height =  160, },
    { .left =  704, .top =  960, .width =  175, .height =  160, },
    { .left =  880, .top =  960, .width =  175, .height =  160, },
    { .left = 1056, .top =  960, .width =  175, .height =  160, },
    { .left = 1232, .top =  960, .width =  175, .height =  160, },
    { .left =    0, .top = 1120, .width =  175, .height =  160, },
    { .left =  176, .top = 1120, .width =  175, .height =  160, },
    { .left =  352, .top = 1120, .width =  175, .height =  160, },
    { .left =  528, .top = 1120, .width =  175, .height =  160, },
    { .left =  704, .top = 1120, .width =  175, .height =  160, },
    { .left =  880, .top = 1120, .width =  175, .height =  160, },
    { .left = 1056, .top = 1120, .width =  175, .height =  160, },
    { .left = 1232, .top = 1120, .width =  175, .height =  160, },
    { .left =    0, .top = 1280, .width =  175, .height =  160, },
    { .left =  176, .top = 1280, .width =  175, .height =  160, },
    { .left =  352, .top = 1280, .width =  175, .height =  160, },
    { .left =  528, .top = 1280, .width =  175, .height =  160, },
    { .left =  704, .top = 1280, .width =  175, .height =  160, },
    { .left =  880, .top = 1280, .width =  175, .height =  160, },
    { .left = 1056, .top = 1280, .width =  175, .height =  160, },
    { .left = 1232, .top = 1280, .width =  175, .height =  160, },
    { .left =    0, .top = 1440, .width =  175, .height =  160, },
    { .left =  176, .top = 1440, .width =  175, .height =  160, },
    { .left =  352, .top = 1440, .width =  175, .height =  160, },
    { .left =  528, .top = 1440, .width =  175, .height =  160, },
    { .left =  704, .top = 1440, .width =  175, .height =  160, },
    { .left =  880, .top = 1440, .width =  175, .height =  160, },
    { .left = 1056, .top = 1440, .width =  175, .height =  160, },
    { .left = 1232, .top = 1440, .width =  175, .height =  160, },
    { .left =    0, .top = 1600, .width =  175, .height =  160, },
    { .left =  176, .top = 1600, .width =  175, .height =  160, },
    { .left =  352, .top = 1600, .width =  175, .height =  160, },
    { .left =  528, .top = 1600, .width =  175, .height =  160, },
    { .left =  704, .top = 1600, .width =  175, .height =  160, },
    { .left =  880, .top = 1600, .width =  175, .height =  160, },
    { .left = 1056, .top = 1600, .width =  175, .height =  160, },
    { .left = 1232, .top = 1600, .width =  175, .height =  160, },
    { .left =    0, .top =    0, .width =    0, .height =    0, },
};

