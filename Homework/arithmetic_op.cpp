#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

int main()
{
    Mat m1(3, 6, CV_8UC1, Scalar(10));
    Mat m2(3, 6, CV_8UC1, Scalar(50));
    Mat m_add1, m_add2, m_sub, m_div1, m_div2;
    Mat mask(m1.size(), CV_8UC1);   //mask 행렬 선언

    Rect rect(Point(3,0), Size(3,3));   //관심영역 지정
    mask(rect).setTo(1);        //rect 사각형의 영역만큼 원소값 지정

    add(m1, m2, m_add1);    //행렬 덧셈 수행
    add(m1, m2, m_add2, mask);  //mask 영역만 덧셈 수행
    divide(m1, m2, m_div1);
    m1.convertTo(m1, CV_32F);   //형 변환 해주는 함수
    m2.convertTo(m2, CV_32F);
    divide(m1, m2, m_div2);

    cout << "[m1] = " << endl << m1 << endl;
    cout << "[m2] = " << endl << m2 << endl;
    cout << "[mask] = " << endl << mask << endl << endl;
    
    cout << "[m_add1] = " << endl << m_add1 << endl;
    cout << "[m_add2] = " << endl << m_add2 << endl;
    cout << "[m_div1] = " << endl << m_div1 << endl;
    cout << "[m_div2] = " << endl << m_div2 << endl;
        
    return 0;    
}