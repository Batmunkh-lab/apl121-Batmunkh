# Тооцоо хуваах — псевдокод

ЭХЛЭХ

1. Хүний тоо n-ийг оруулна.
   5–20 хооронд биш бол дахин асууна.

2. Хоолны нийт үнэ total-ийг оруулна.
   1–1000000 хооронд биш бол дахин асууна.

3. Үйлчилгээний хураамж fee-г оруулна.
   0–100000 хооронд биш бол дахин асууна.

4. ДАВТ:
   sum = 0
   Хүн бүрийн хувьд:
       order[i]-г 0–total хүрээнд оруулна.
       sum = sum + order[i]

   ХЭРЭВ sum < total:
       Нийлбэр бага гэсэн мэдээлэл хэвлэнэ.
   ЭСВЭЛ ХЭРЭВ sum > total:
       Нийлбэр их гэсэн мэдээлэл хэвлэнэ.
   БУСАД ҮЕД:
       Нийлбэр таарсан гэсэн мэдээлэл хэвлэнэ.
   sum нь total-тай тэнцэх хүртэл давтана.

5. cumulative = 0
   previous = 0

6. Хүн бүрийн хувьд:
   cumulative = cumulative + order[i]
   allocated = бүхэл_хэсэг(cumulative × fee / total)
   service[i] = allocated - previous
   pay[i] = CalculatePay(order[i], service[i])
   previous = allocated
   used[i] = 0

7. Хүн бүрийн захиалга, хураамж, төлөх дүнг хүснэгтээр хэвлэнэ.
   Нийт захиалга total, хураамж fee, төлбөр total + fee-г хэвлэнэ.

8. rank = 1-ээс 3 хүртэл:
   best = -1
   Хүн бүрийн хувьд:
       ХЭРЭВ used[i] = 0:
           ХЭРЭВ best = -1:
               best = i
           ЭСВЭЛ ХЭРЭВ pay[i] > pay[best]:
               best = i

   used[best] = 1
   Байр, хүний дугаар, төлөх дүнг хэвлэнэ.

ДУУСАХ
ФУНКЦ CalculatePay(amount, charge):
    result = amount + charge
    result-ийг буцаана.