function DT=canny_edge(img)

[H,W] = size(img);%��ȡͼ���С
r=1;
sigma=1*r;
gausFilter = fspecial('gaussian',[2*r+1 2*r+1],sigma);
A=imfilter(img,gausFilter,'replicate'); 

dx = [-1 0 1;-1 0 1;-1 0 1];%x������ݶ�ģ��
dy = [1 1 1;0 0 0;-1 -1 -1];%y������ݶ�ģ��

gx = conv2(A,dx,'same');%��ȡx������ݶ�ͼ��.ʹ���ݶ�ģ����ж�ά���,�����ԭͼ���С��ͬ
gy = conv2(A,dy,'same');%��ȡy������ݶ�ͼ��.ʹ���ݶ�ģ����ж�ά���,�����ԭͼ���С��ͬ
M = sqrt((gx.^2) + (gy.^2));%��ȡ��ֵͼ��.��С��ԭͼ�����.(.^)��ʾ����˷�
a = atan2(gy,gx);%��ȡ���ȣ���Χ��-pi~pi
a= a*180/pi;%������ת��Ϊ�Ƕȣ��õ��Ƕ�ͼ����ԭͼ���С���.

for i = 1:H
    for j = 1:W
        if((a(i,j) >= -22.5) && (a(i,j) < 0)||(a(i,j) >= 0) && (a(i,j) < 22.5) || (a(i,j) <= -157.5) && (a(i,j) >= -180)||(a(i,j) >= 157.5)&&(a(i,j) <= 180))
            a(i,j) = 0;
        elseif((a(i,j) >= 22.5) && (a(i,j) < 67.5) || (a(i,j) <= -112.5) && (a(i,j) > -157.5))
            a(i,j) = 45;
        elseif((a(i,j) >= 67.5) && (a(i,j) < 112.5) || (a(i,j) <= -67.5) && (a(i,j) >- 112.5))
            a(i,j) = 90;
        elseif((a(i,j) >= 112.5) && (a(i,j) < 157.5) || (a(i,j) <= -22.5) && (a(i,j) > -67.5))
            a(i,j) = -45;  
        end
    end
end

Nms2 =M;%����һ���Ǽ���ֵͼ��

for i = 3:H-2
    for j= 3:W-2
        %
        if a(i,j) == 0 && M(i,j) ~= max(M(i,j-1:j+1))
            Nms2(i,j) =0;
        elseif a(i,j) ==45 && M(i,j) ~= max([M(i,j), M(i+1,j-1),M(i-1,j+1)]) %,M(i+2,j-2),M(i-2,j+2)])%
            Nms2(i,j) = 0;
        elseif a(i,j) == 90 && M(i,j) ~= max(M(i-1:i+1,j))
            Nms2(i,j) = 0;
        elseif a(i,j) == -45 && M(i,j) ~= max([M(i,j), M(i+1,j+1), M(i-1,j-1)]) %, M(i+2,j+2), M(i-2,j-2)]) %
            Nms2(i,j) = 0;
        end;
    end;
end;

Nms=(Nms2-min(min(Nms2)))/(max(max(Nms2))-min(min(Nms2)));
DT=(Nms>0.01);
DT(:,1)=0;DT(1,:)=0;DT(H,:)=0;DT(:,W)=0;
% figure
% imshow(DT)
% DT = zeros(H,W);%����һ��˫��ֵͼ��
% 
% TH = 0.5*max(max(Nms));%����ֵ
% TL = 0.3*max(max(Nms));%����ֵ
% for i = 2  : H-1
%     for j = 2 : W-1
%         if (Nms(i, j) <= TL)
%             DT(i,j) = 0;
%         elseif (Nms(i, j) > TH)
%             DT(i,j) = 1 ;
%         %��TL < Nms(i, j) < TH ʹ��8��ͨ����ȷ��
%         elseif ( Nms(i+1,j) > TH || Nms(i-1,j) > TH || Nms(i,j+1) > TH || Nms(i,j-1) > TH || Nms(i-1, j-1) > TH || Nms(i-1, j+1) > TH || Nms(i+1, j+1) > TH || Nms(i+1, j-1) > TH)
%             DT(i,j) = 1;
%         end;
%     end;
% end;
end