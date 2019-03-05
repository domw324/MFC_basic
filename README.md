# MFC_basic
MFC 기본 과제 - Simple Sketch Demo program 제작

해야할 것 목록을 작성해보자.

<h3> 보완점 </h3>
1.  메인 프레임 단계에서 실행하도록
    [Ctrl + Z] 스케치 되돌리기 : 이벤트 함수 사용 -> ID_EDIT_UNDO 사용.
2.  현재 ID_FILE_OPEN을 활용하여 문서 열기 가능.
    But, ID_FILE_SAVE 혹은 ID_FILE_SAVE_AS를 사용할 경우, 새로 정의한 함수가 아닌 Default 함수가 호출 됨.
    -> CDocument에서 Overriding 불가하게 작성해 놓음. 해결책 탐색

<h3 발전방향>
1.  Object Tree/Sketch View에서 마우스 활용하여 요소 선택 가능 + 하이라이트(색 변경) 기능
2.  Shape 종류 추가(도형 종류, 일반 스케치 모드, 레이어 등) + 수정 기능(색, 사이즈, 채우기 등)
3.  사용성 고려, Tree창과 Function창 분리
