**[hustar_Image_Processing]**  
Hustar에서 진행된 Image_Processing 관련 Project file 입니다.

# Main Project - Road Lane Detection
> **자율주행 SoftWare의 개발을 위한 전처리 단계로서 Road Lane Detection Program을 구현**
> 
> Repository 정리 중 발생된 폴더 이동으로 소스코드 작동이 정상적으로 진행되지 않을 수 있습니다.  
> (**Image File 불러오기 시 경로 수정이 필요**합니다.)  
  
  
## 1. RoadDetection_Binary
![image](https://user-images.githubusercontent.com/84756721/173279345-fcb3d62a-de14-48c7-8782-c00c076814f9.png)

- 도로 주행 영상을 Input으로 받아 GrayScale ➙ Binary Filtering을 통해 도로 상의 선 성분을 구분함
- 이후 Canny Edge Detection과 Hough 변환으로 직선 성분만을 검출함.
- Threshold 값에 의해 구분되다 보니 영상 정보의 밝기, 도로의 상태 등에 성능 편차가 크게 일어남.
- ROI를 세부 조정해서 성능을 올려보려했으나 Binary filtering의 한계가 분명

## 2. RoadDetection_HSV
![image](https://user-images.githubusercontent.com/84756721/173281064-5287dedc-5d9b-4db6-ac17-116dbe72abfa.png)
![image](https://user-images.githubusercontent.com/84756721/173281112-4aed7bf7-9f2d-4cf4-9b53-07e0dbedff59.png)
- 기존에 GrayScale ➙ Binary Filtering의 단점을 HSV 변환으로 개선함.
- HSV 채널 변환을 통해 흰선 이외의 주황선 등의 성분도 검출 ➙ GrayScale을 수행
- 이후 Canny Edge Detection과 Hough Transform은 동일하며 Linear regression을 통해 직선 성분 검출을 보완함.
- Binary Filtering보다 차선 검출에 대한 정확성이 높아졌으나 햇빛에 반사된 도로, 그늘진 도로, 야간 조명 등에 취약한 모습을 보임.  

## 3. RoadDetection_Warping
- 기존 영상 처리 방식은 ROI를 설정하고 ROI 영역 내부에 대한 전처리를 진행함.
- Input 영상마다 차선의 위치가 다르고 차체의 높낮이, 폭, 블랙박스의 위치 등 변수가 많아 일정한 성능을 보이기 어려움
- 이러한 현상 개선을 위해 Bird View 기법을 채택하여 다양한 Input 영상에 대한 성능을 보장함.
  
![image](https://user-images.githubusercontent.com/84756721/173284509-467099bd-ab9e-4f3e-a8b6-5d809630e6d4.png)
![image](https://user-images.githubusercontent.com/84756721/173284572-b4d0fdfd-a5b5-49fe-8f48-042727014049.png)
- 지정한 범위 (ROI)에 대해 Warping을 수행함
- ROI 범위마다 차이는 있을 수 있으나 대체적으로 차체 앞의 도로 이미지만 Warping을 통해 전처리할 수 있으므로 여러 Input 영상에 대해 성능을 일정하게 유지할 수 있을 것이라 기대함.
- Camera Calibration이 적용되지 않아 왜곡이 다소 심하고 Filtering 기법이 이전 방법과 동일하여 성능 개선이 크지 않음.
- 짧은 프로젝트 기간으로 인한 완성도가 미흡함.

## 총평
|Technique|pros and cons|
|---|---|
|**Binary Transform**|- 가장 직관적인 방법으로 구현이 쉽고 동작이 빠름</br>- Threshold 값에 따라 구분되므로 높은 성능을 기대하기 힘듦</br>- 도로 잡음 데이터에 대한 내성이 매우 약함|
|**HSV Color Transform**|- Binary Transform 보다 준수한 성능을 보임</br>- 밝기 값과 색상 정보를 통해 차선을 검출하므로 중앙선 등 검출 성능 향상</br>- 밝은 도로, 그늘진 도로, 야간 조명 등에 대한 내성이 약함|
|**Bird-View Transform**|- 범위 지정을 통해 Warping이 이루어지므로 지정 범위 이외의 노이즈 제거가 가능</br>- 근본적인 Filtering 연산에 대한 개선이 필요|
  
- 약 1주 정도의 짧은 프로젝트 기간 동안 진행하였기 때문에 최종 구현물의 퀄리티가 아쉬웠음.
- 다양한 기법을 적용하여 비교해본 결과 이번 Project에서는 HSV Transform 기법이 가장 뛰어난 것으로 측정됨.
