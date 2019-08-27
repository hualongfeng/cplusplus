#include<iostream>
#include<string>
#include<rados/librados.hpp>

int main()
{
librados::Rados cluster;
cluster.init("admin");
cluster.connect();

librados::IoCtx pool;
cluster.ioctx_create("my_pool", pool);

librados::bufferlist data;
data.append("Hello world!");
pool.write_full("my object", data);

librados::bufferlist attr;
attr.append("1");
pool.setxattr("my object", "version", attr);

librados::bufferlist data2;
pool.read("my object", data2, data.length(), 0);
assert(data.contents_equal(data2));

cluster.shutdown();

return 0;

}

