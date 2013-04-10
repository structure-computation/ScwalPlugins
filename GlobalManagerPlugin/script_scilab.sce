im=imread('/home/ubuntu/Scwal/EcosystemScience/data.db/1714636915');
faces = detectfaces(im);
[m,n] = size(faces);
for i=1:m,
     im = rectangle(im, faces(i,:), [0,255,0]);
end;
imf=im;
imwrite(imf,'/home/ubuntu/Scwal/EcosystemScience/data.db/1714636915result.png');
