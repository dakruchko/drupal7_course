Menu:

1)      ������� ����� ���� � ������� training/menu � � ���������� �Training Landing Page�, ����� ���� ������ ���������� � �Navigation� ����. ����� ���� ������ ���� ������� �� ���������.
2)      ��� �������� �� ��� �������� ������ ������������ ����� �This is the landing page of the Training module�
3)      ������� ����� ���� � ������� training/menu/custom_access � � ���������� �Custom Access Menu Item�. ����� ���� ������ ���� ����� ������ �������������� �������������.  ���� �authenticated user�.
4)      ������� ����� ���� � ������� training/menu/permissioned � � ���������� �Permissioned Menu Item�. ����� ���� ������ ���� ����� ������ ������������� � ������  �access protected menu example�.
5)      ������� ����� ���� � ������� training/menu/callback. ���� ����� �� ������ ������� �� � ���� ����. �� �������� ������ ���� ������� �The menu entry for this page is of type MENU_CALLBACK�
6)      ������� ������ ���� � ������. ���� ���������� �� ������ training/menu/tabs, ��������� �������� ������ �Tabs�. �� �������� ������ ���������� ������� �This is the "tabs" menu entry�. � ����� ������ ���� ��������� ��������.
training/menu/tabs/second
training/menu/tabs/third
training/menu/tabs/fourth
������ �������� ������ �������� ����� �� �������
�This is the tab "%name" in the "basic tabs" example� ��� %name � second, third, fourth
7)      � ������ �������� ����������� ����� ������� ��������
training/menu/tabs
training/menu/tabs/default/second
training/menu/tabs/default/third
8)      ������� ����� ����, ������� ����� ��������� � ������������ 2 ���������.
training/menu/arguments/%1/%2
���� �������� ������ �������� ��� ���������
training/menu/arguments/one/two ���������
Argument 1=one
Argument 2=two
�������� ����� �� ��������� ���������.
9)      ������� �������� � ������������ ������� training/menu/placeholder/%/display.
�������� ������ �������� ������������ �������� <div>%</div>
10)   ������� ���������� ���������. �������� � �������� ������ training/menu/default_arg/%
������ ������������ �������� � �������� ��� ������������ ��������
1 => 'one',
2 => 'two',
3 => 'three',
99 => 'Almost there'
��� ������ ��������� ��������� ������ ������������ �������� 404.
11)   ������� �������� �� ������ training/menu/title � ������������ ���������� �� ������� �Dynamic title: username= %username�. ��� %username � ��� ������������ ������������, ��� ������� ��������  anonymous.
12) ������� ����� ���� training/menu/main � ���������� �Item in main menu� ������� ����� ��������� � ������� ���� (main-menu)

Themes
1 ������� ����� ���� �training/theme�, �� �������� ���������� ����������� ������ �� ������ �� ��� �������� �������� ���:
? theme/list - List
? theme/table - Table
? theme/image - image
? theme/access - Access
��������� ������ - �Links to themes�. 
2 ������� �������� training/theme/table � ���������� ������� � 3�� ���������. 
? �������� ������� �Theme table sample�, �������� �table-test�. 
? ��������� �������� �header 1�, �header 2�, �header 3�. 
? � ����� ������ ���� ����� �rowClass� � ������������ �even�-�odd�. 
? ������ ������ ������ �������� 2 ������.
3 ������� �������� training/theme/image � ���������� ��������� ��������
? modules/image/sample.png � ������� simple-image
? ��������� ��� ��������� ����� ����������� � ���� �������� � ������� �� �������
4 ������� �������� training/theme/access � ���������� ��������� �����
? �Custom access for rendered content� ��� ������������� � ������� ���� ����� �access protected content�.
? �Custom access inversed for rendered content� ��� ������������� � ������� ��� ����� �access protected content�.
