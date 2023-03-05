#include "pch.h"
#include "TestKdTree.h"
#if __has_include("TestKdTree.g.cpp")
#include "TestKdTree.g.cpp"
#endif

using namespace winrt;
using namespace Windows::UI::Xaml;

namespace winrt::BingKDTree::implementation
{
    TestKdTree::TestKdTree()
    {
        InitializeComponent();
    }

    int32_t TestKdTree::MyProperty()
    {
        throw hresult_not_implemented();
    }

    void TestKdTree::MyProperty(int32_t /* value */)
    {
        throw hresult_not_implemented();
    }

    void TestKdTree::ClickHandler(IInspectable const&, RoutedEventArgs const&)
    {
        Button().Content(box_value(L"Clicked"));
    }
}
