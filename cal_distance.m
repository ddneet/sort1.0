% cal distance of jump-jump
%��ʼ��
fid=fopen('D:\00\shotpic\id.txt','w');
fprintf(fid,'0');
fclose(fid);
fid=fopen('D:\00\shotpic\distance.txt','w');
fprintf(fid,'stop');
fclose(fid);

mid=0;%center=[(720-750/2)*2,1305];
player=im2double(imread('D:\00\prepic\player2.png'));
% point=im2double(imread('D:\00\prepic\white_circle.png'));
isend=0;
while isend==0
    load('D:\00\shotpic\id.txt')
    if id>mid % �������
        mid=id+1;
        name=strcat('D:\00\shotpic\',num2str(id),'.png');
        shot=im2double(imread(name));
        shot=imrotate(shot,-90);
        
        [x,y]=match(player,shot);
        if x>0 && y>0
            [tx,ty]=match_point(shot);
            if tx==0 && ty==0
                [tx,ty]=cal_tarpos(rgb2gray(shot));
            end
%             distance=abs(center(2)-x-x)*abs(center(2)-x-x)+abs(center(1)-y-y)*abs(center(1)-y-y);
%             distance=sqrt(distance);
            distance=(tx-x)*(tx-x)+(ty-y)*(ty-y);
            distance=sqrt(distance);
            pause(1);
            fid=fopen('D:\00\shotpic\id.txt','w');
            fprintf(fid,num2str(mid));
            fclose(fid);
            fid=fopen('D:\00\shotpic\distance.txt','w');
            fprintf(fid,num2str(distance));
            fclose(fid);
            pause(2);
        else
            isend=1;
            fid=fopen('D:\00\shotpic\id.txt','w');
            fprintf(fid,'-1');
            fclose(fid);
        end
    else
        pause(0.7);
    end
end
