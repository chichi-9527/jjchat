# jjchat
## server
使用 boost 1.83

server 使用 boost/asio tcp/ipv4 实现, 支持多线程, 支持多客户端.

使用 boost/mysql 实现数据库操作. boost/json 实现 json 解析.

使用字节流传输数据，序列化工具为 potatobuf.
[potatobuf](https://github.com/chichi-9527/potatobuf)

### 使用
- 继承 TcpServer 类，实现 _deal_head_msg 函数.
- 通过 Client::get_buf 获取消息头字节流 Client::head_size 获取消息头长度，解析消息头.
- 消息头长度在 TcpServer 构造函数中设置.
- TcpServer::start 启动服务.(指定消息头处理线程数和消息处理线程数， 默认 1 个消息头处理线程和 1 个消息处理线程)



## client

使用qt实现.（qt 6.7.0）

客户端消息存储使用 qt 自带的 QSqlDatabase 类.（未完成）

## database

使用 mysql 8.0.33.

- 初始表 users
字段：

| 字段名 | 类型 | 注释 |
| --- | --- | --- |
| user_id | bigint | 自增主键 |
| name | varchar(14) | 用户名 |
| sign_up_time | datetime | 注册时间 |
| password | varchar(255) | 密码 |
| salt1 | char(5) | client盐 |
| salt2 | char(5) | server盐 |
| avatar_type | int | 头像类型 |
| avatar_path | varchar(255) | 头像路径 |

- 当有新用户注册时，生成表 user_##user_id##_friends （user_id 为用户id），用于存储用户的好友与群列表.和表 message_people_##user_id （user_id 为用户id）.
user_##user_id##_friends字段：

| 字段名 | 类型 | 注释 |
| --- | --- | --- |
| type | int | 类型 |
| friend_group_id | bigint | 好友或群id |
| create_time | datetime | 创建时间 |

message_people_user_id字段：

| 字段名 | 类型 | 注释 |
| --- | --- | --- |
| message_id | bigint | 消息id |
| message_type | int | 消息类型 |
| people_group_id | bigint | 消息接收者id |
| message_data | varchar(255) | 消息内容 |
| is_read | int | 是否已读 |
| message_time | datetime | 消息时间 |
- 创建表 message_group_group_id （group_id 为群id），用于存储群消息时同理.