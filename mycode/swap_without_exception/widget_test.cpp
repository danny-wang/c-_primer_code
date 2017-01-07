
#include "Widget.h"
#include "gtest/gtest.h"
using namespace std;


TEST(widget_test, class_widget) {
 
    using namespace WidgetStuff;
    WidgetImpl widget_impl1(1,2,3,{1.0,2.0,3.0});
    WidgetImpl widget_impl2(4,5,6,{4.0,5.0,6.0});

    Widget widget_1(&widget_impl1);
    Widget widget_2(&widget_impl2);
    EXPECT_EQ(widget_1.get_a(),1);
    EXPECT_EQ(widget_2.get_a(),4);
    using std::swap;
    swap(widget_1,widget_2);
    EXPECT_EQ(widget_1.get_a(),4);
    EXPECT_EQ(widget_2.get_a(),1);

}